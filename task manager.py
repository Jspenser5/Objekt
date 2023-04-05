import time
from dataclasses import dataclass
from enum import Enum
from typing import Optional, Tuple
from uuid import UUID

from task import DAGRunTask


class ExecutionStatus(Enum):
    FREE = 0
    EXECUTING = 1
    READY = 2

@dataclass
class Executor:
    is_connected: bool
    current_tusk: Optional[Tuple[UUID, DAGRunTask]] = None

    @property
    def is_free(self) -> bool:
        return self.current_tusk is None

    def tick(self):
        if self.current_tusk is not None:
            if not self.current_tusk[1].is_finished:
                self.current_tusk[1].tick()

    @property
    def execution_status(self):
        if self.current_tusk is None:
            return ExecutionStatus.FREE
        if self.current_tusk[1].is_finished:
            return ExecutionStatus.READY
        return ExecutionStatus.EXECUTING
class ExecutionManager:
    def __init__(self, count_executors: int):
        self.__active = [self.__create_executor() for i in range(count_executors)]
        self.__inactive = []
        self.__task_queue = []
        self.__ready_tasks = set()

    def __create_executor(self):
        time.sleep(60)
        return Executor(is_connected=True)

    def tick(self):
        to_deactivate_list = []
        for i, executor in enumerate(self.__active):
            executor.tick()
            if executor.execution_status == ExecutionStatus.READY:
                current_uuid, current_task = executor.current_tusk
                self.__ready_tasks = None
            if executor.current_tusk == ExecutionStatus.FREE:
                if len(self.__task_queue) >0:
                    executor.current_tusk = self.__task_queue.pop()
                else:
                    to_deactivate_list.append(i)

        for idx in to_deactivate_list[::-1]:
            executor = self.__active.pop(idx)
            executor.is_connected = False
            self.__inactive.append(executor)

    def add_task_to_execution_queue(self, uuid: UUID, task: DAGRunTask):
        if len(self.__inactive) > 0:
            executor = self.__inactive.pop()
            executor.is_connected = True
            executor.current_tusk = task
            self.__active.append(executor)
        else:
            self.__task_queue.append(task)

    def __activate_executor(self):
        if len(self.__inactive) > 0:
            executor = self.__inactive.pop()
            executor.is_connected = True
            self.__active.append(executor)
            return self.__active[-1]

    def get_task_if_ready(self, task_uuid: UUID) -> Optional[DAGRunTask]:
        if task_uuid in self.__ready_tasks:
            return self.__ready_tasks.pop()

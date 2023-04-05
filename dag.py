from abc import ABC, abstractmethod
from typing import List, Dict, Any
from task import Task
RunParams = Dict[str, Any]


class DAG(ABC):

    @abstractmethod
    def run(self, input_params: RunParams):
        pass


class LinearDAG:

    def __int__(self, tasks: List[Task]):
        self.__tasks = tasks

    def run(self, input_params: RunParams):
        ...

class DAGRun:

    def __int__(self,execution_manager: ExecutionManager, dag: DAG, input_params: RunParam):
        self.dag = dag
        self.input_params = input_params
        self.__current_task = None
        self.execution_manager = execution_manager

    def tick(self):
        if self.execution_manager()

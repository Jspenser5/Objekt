from typing import Callable, Optional
from time import sleep
from dag import RunParams


class Task:

    def __int__(self, func: Callable[[RunParams], Optional[RunParams]],
                      t: Optional[int] = 10):
        self.__func = func
        self.__t = t

    def run(self, input_params: RunParams) -> DAGRunTask:
        return DAGRunTask(self.__func, input_params = input_params, t = self.__t)


class DAGRunTask:

    def __int__(self, func: Callable[[RunParams], Optional[RunParams]],
                    input_params: Optional[RunParams] = None,
                    t: Optional[int] = 10):
        self.__func = func
        self.__input_params = input_params
        self.__t = t
        self.i = 0
        self.is_finished = False
        self.__output = None

    def tick(self):
        if self.i < self.__t - 1:
            self.i += 1
            sleep(1)
        else:
            self.__output = self.__func(self.__input_params)
            self.is_finished = True

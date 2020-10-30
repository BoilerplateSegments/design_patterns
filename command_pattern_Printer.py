# a command queue pattern sample

from collections import deque

class Handler():
    """The INVOKER/HANDLER class"""
    def __init__(self) -> None:
        self._history = deque()

    @property
    def history(self):
        return self._history

    def execute(self, command) -> None:
        self._history.appendleft(command)
        command.execute()
  
## COMMAND wrapper
class Command():
    def __init__(self,object) -> None:
        self._obj=object
    
    def execute(self):
        return NotImplementedError

# various commands
class PrintACommand(Command):
    def execute(self) -> None:
        self._obj.printA()

class PrintBCommand(Command):
    def execute(self) -> None:
        self._obj.printB()
##

class commandReceiver():
    """The RECEIVER/LISTENER class"""
    def printA(self):
        print("A")
    def printB(self):
        print("B")

class printerClient():
    def __init__(self) -> None:
        self._receiver = commandReceiver()
        self._handler=Handler()

    @property
    def handler(self):
        return self._handler
    
    def run(self,command:str):
        command = command.strip().upper()
        if command == "PRINTA":
            self._handler.execute(PrintACommand(self._receiver))
        elif command == "PRINTB":
            self._handler.execute(PrintBCommand(self._receiver))

if __name__ == "__main__":
    myPrint=printerClient()
    myPrint.run("printA")
    myPrint.run("printB")
    myPrint.run("printB")
    
    for x in myPrint.handler.history:
        print(x.__class__.__name__)

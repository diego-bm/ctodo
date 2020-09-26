#include <iostream>
#include <string>

using namespace std;

class Task
{
public:
  string desc;
  bool done = false;

  void completed()
  {
    done = true;
  }
};

string ask(string question)
{
  cout << question << endl;
  string answer;
  getline(cin, answer);
  return answer;
}

void listTasks(Task taskList[], Task firtTask[])
{
  int index = 0;
  Task *previusTask = taskList;
  taskList = firtTask;

  while (taskList[index].desc != "")
  {
    cout << (index + 1) << ". ";

    if (taskList[index].done)
    {
      cout << " (Done)";
    }

    cout << taskList[index].desc;

    cout << endl;

    index++;
  }

  taskList = previusTask;
}

Task *addTask(Task taskList[])
{
  string input = ask("Ingrese nombre tarea:");
  Task newTask;
  newTask.desc = input;
  *taskList = newTask;
  return ++taskList;
}

void completeTask(Task taskList[], Task firtTask[])
{
  string input = ask("Ingrese numero tarea:");
  int index = stoi(input) - 1;

  Task *previusTask = taskList;
  taskList = firtTask;

  taskList[index].completed();

  taskList = previusTask;
}

int showMenu()
{
  cout << "1. Listar tareas" << endl;
  cout << "2. Agregar tarea" << endl;
  cout << "3. Completar tarea" << endl;
  cout << "4. Borrar tarea" << endl;
  cout << "5. Salir" << endl;

  string input = ask("Seleccione una opción:");
  int option = stoi(input);

  return option;
}

int main()
{
  cout << "## Tareas ##" << endl;

  Task *taskList;
  taskList = new Task[10];
  Task *firstTask = taskList;

  bool exit = false;

  do
  {
    cout << endl;
    int option = showMenu();
    cout << endl;

    switch (option)
    {
    case 1:
      listTasks(taskList, firstTask);
      break;
    case 2:
      taskList = addTask(taskList);
      break;
    case 3:
      completeTask(taskList, firstTask);
      break;
    case 5:
      exit = true;
      break;

    default:
      break;
    }
  } while (!exit);
}

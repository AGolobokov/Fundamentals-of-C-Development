#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

// Перечислимый тип для статуса задачи
// enum class TaskStatus {
//   NEW,          // новая
//   IN_PROGRESS,  // в разработке
//   TESTING,      // на тестировании
//   DONE          // завершена
// };

// // Объявляем тип-синоним для map<TaskStatus, int>,
// // позволяющего хранить количество задач каждого статуса
// using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  map<string, TasksInfo> person_task_info;    
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
    return person_task_info.at(person);
  }

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person) {
    person_task_info[person][TaskStatus::NEW]++;
  }
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count) {
        TasksInfo updated;
        TasksInfo untouched;
        // cout << "task_count = " << task_count << endl;

        int save_new_task         = person_task_info[person][TaskStatus::NEW];
        int save_in_progress_task = person_task_info[person][TaskStatus::IN_PROGRESS];
        int save_testing_task     = person_task_info[person][TaskStatus::TESTING];
        int save_done_task        = person_task_info[person][TaskStatus::DONE];

        if (task_count > save_new_task + save_in_progress_task + save_testing_task) {
          task_count = save_new_task + save_in_progress_task + save_testing_task;
        }

        if (task_count <= save_new_task) {
          // MOVE 
          person_task_info[person][TaskStatus::NEW] = save_new_task - task_count;
          person_task_info[person][TaskStatus::IN_PROGRESS] += task_count;
          // field
          updated[TaskStatus::NEW]         = person_task_info[person][TaskStatus::NEW] - save_new_task;
          updated[TaskStatus::IN_PROGRESS] = person_task_info[person][TaskStatus::IN_PROGRESS] - save_in_progress_task;
          updated[TaskStatus::TESTING]     = person_task_info[person][TaskStatus::TESTING] - save_testing_task;
          updated[TaskStatus::DONE]        = person_task_info[person][TaskStatus::DONE] - save_done_task;

          if (updated[TaskStatus::NEW] <= 0) {
            updated.erase(TaskStatus::NEW);
          }
          if (updated[TaskStatus::IN_PROGRESS] <= 0) {
            updated.erase(TaskStatus::IN_PROGRESS);
          }
          if (updated[TaskStatus::TESTING] <= 0) {
            updated.erase(TaskStatus::TESTING);
          }
          if (updated[TaskStatus::DONE] <= 0) {
            updated.erase(TaskStatus::DONE);
          }
          untouched[TaskStatus::NEW] = save_new_task - task_count;

          untouched[TaskStatus::IN_PROGRESS] = save_in_progress_task;
          if (save_testing_task - person_task_info[person][TaskStatus::TESTING] != 0) {
            untouched[TaskStatus::TESTING] = save_testing_task - person_task_info[person][TaskStatus::TESTING];
          } else {
            untouched[TaskStatus::TESTING] = save_testing_task;
          }

          if (untouched[TaskStatus::NEW] <= 0) {
            untouched.erase(TaskStatus::NEW);
          }
          if (untouched[TaskStatus::IN_PROGRESS] <= 0) {
            untouched.erase(TaskStatus::IN_PROGRESS);
          }
          if (untouched[TaskStatus::TESTING] <= 0) {
            untouched.erase(TaskStatus::TESTING);
          }
          if (untouched[TaskStatus::DONE] <= 0) {
            untouched.erase(TaskStatus::DONE);
          }
          if (updated[TaskStatus::NEW] <= 0) {
            updated.erase(TaskStatus::NEW);
          }
          if (updated[TaskStatus::IN_PROGRESS] <= 0) {
            updated.erase(TaskStatus::IN_PROGRESS);
          }
          if (updated[TaskStatus::TESTING] <= 0) {
            updated.erase(TaskStatus::TESTING);
          }
          if (updated[TaskStatus::DONE] <= 0) {
            updated.erase(TaskStatus::DONE);
          }
          
        } else {
          if (task_count <= (save_new_task + save_in_progress_task)) {
            // MOVE 
            int task_count_part = task_count - person_task_info[person][TaskStatus::NEW];

            person_task_info[person][TaskStatus::NEW] = 0;
            person_task_info[person][TaskStatus::IN_PROGRESS] = save_new_task + save_in_progress_task - task_count + save_new_task;
            untouched[TaskStatus::IN_PROGRESS] = save_in_progress_task - task_count_part;
            person_task_info[person][TaskStatus::TESTING] += task_count_part;

            // field
            updated[TaskStatus::NEW]         = person_task_info[person][TaskStatus::NEW] - save_new_task;
            updated[TaskStatus::IN_PROGRESS] = save_new_task;
            updated[TaskStatus::TESTING]     = person_task_info[person][TaskStatus::TESTING] - save_testing_task;
            updated[TaskStatus::DONE]        = person_task_info[person][TaskStatus::DONE] - save_done_task;

            if (updated[TaskStatus::NEW] <= 0) {
              updated.erase(TaskStatus::NEW);
            }
            if (updated[TaskStatus::IN_PROGRESS] <= 0) {
              updated.erase(TaskStatus::IN_PROGRESS);
            }
            if (updated[TaskStatus::TESTING] <= 0) {
              updated.erase(TaskStatus::TESTING);
            }
            if (updated[TaskStatus::DONE] <= 0) {
              updated.erase(TaskStatus::DONE);
            }
            if (save_new_task > 0) {
              untouched[TaskStatus::NEW] = updated[TaskStatus::NEW] - save_new_task;
            }

            if (save_testing_task > 0) {
              untouched[TaskStatus::TESTING] = save_testing_task - updated[TaskStatus::DONE];
            }
            
            if (untouched[TaskStatus::NEW] <= 0) {
              untouched.erase(TaskStatus::NEW);
            }
            if (untouched[TaskStatus::IN_PROGRESS] <= 0) {
              untouched.erase(TaskStatus::IN_PROGRESS);
            }
            if (untouched[TaskStatus::TESTING] <= 0) {
              untouched.erase(TaskStatus::TESTING);
            }

            if (updated[TaskStatus::NEW] <= 0) {
              updated.erase(TaskStatus::NEW);
            }
            if (updated[TaskStatus::IN_PROGRESS] <= 0) {
              updated.erase(TaskStatus::IN_PROGRESS);
            }
            if (updated[TaskStatus::TESTING] <= 0) {
              updated.erase(TaskStatus::TESTING);
            }
            if (updated[TaskStatus::DONE] <= 0) {
              updated.erase(TaskStatus::DONE);
            }
          } else {
            if (task_count <= (save_new_task + save_in_progress_task + save_testing_task)) {

              int task_count_part_in_progress = task_count - person_task_info[person][TaskStatus::NEW];
              int task_count_part_testing = task_count - person_task_info[person][TaskStatus::NEW] - person_task_info[person][TaskStatus::IN_PROGRESS];
              person_task_info[person][TaskStatus::NEW] = 0;
              person_task_info[person][TaskStatus::IN_PROGRESS] = save_new_task; 
              person_task_info[person][TaskStatus::TESTING] = save_testing_task - task_count_part_testing + save_in_progress_task;
              person_task_info[person][TaskStatus::DONE] += task_count_part_testing;

              untouched[TaskStatus::TESTING] = save_testing_task - task_count_part_testing;

              updated[TaskStatus::IN_PROGRESS] = save_new_task;
              updated[TaskStatus::TESTING] = save_in_progress_task;
              updated[TaskStatus::DONE] = person_task_info[person][TaskStatus::DONE] - save_done_task;

              if (updated[TaskStatus::NEW] <= 0) {
                updated.erase(TaskStatus::NEW);
              }
              if (updated[TaskStatus::IN_PROGRESS] <= 0) {
                updated.erase(TaskStatus::IN_PROGRESS);
              }
              if (updated[TaskStatus::TESTING] <= 0) {
                updated.erase(TaskStatus::TESTING);
              }
              if (updated[TaskStatus::DONE] <= 0) {
                updated.erase(TaskStatus::DONE);
              }

              if (untouched[TaskStatus::NEW] <= 0) {
                untouched.erase(TaskStatus::NEW);
              }
              if (untouched[TaskStatus::IN_PROGRESS] <= 0) {
                untouched.erase(TaskStatus::IN_PROGRESS);
              }
              if (untouched[TaskStatus::TESTING] <= 0) {
                untouched.erase(TaskStatus::TESTING);
              }
              
            }
          }
        }

        if (person_task_info[person][TaskStatus::NEW] <= 0) {
          person_task_info[person].erase(TaskStatus::NEW);
        }
        if (person_task_info[person][TaskStatus::IN_PROGRESS] <= 0) {
          person_task_info[person].erase(TaskStatus::IN_PROGRESS);
        }
        if (person_task_info[person][TaskStatus::TESTING] <= 0) {
          person_task_info[person].erase(TaskStatus::TESTING);
        }
        if (person_task_info[person][TaskStatus::DONE] <= 0) {
          person_task_info[person].erase(TaskStatus::DONE);
        }

        return tie(updated, untouched);
      }
};


// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}


// int main() {
//   TeamTasks tasks;
//   // tasks.AddNewTask("Ilia");
//   for (int i = 0; i < 10; ++i) {
//     tasks.AddNewTask("Ivan");
//   }
//   // cout << "Ilia's tasks: ";
//   // PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
//   cout << "Ivan's tasks: ";
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
//   TasksInfo updated_tasks, untouched_tasks;
  
//   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 10);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//   cout << "__________________________________________" << endl;
  
//   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 10);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//   cout << "__________________________________________" << endl;

//   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 10);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//   cout << "__________________________________________" << endl;


//   for (int i = 0; i < 3; ++i) {
//     tasks.AddNewTask("Ivan");
//   }

//   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 3);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//   cout << "__________________________________________" << endl;

//   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 3);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//   cout << "__________________________________________" << endl;

//   for (int i = 0; i < 2; ++i) {
//     tasks.AddNewTask("Ivan");
//   }
  
//   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//   cout << "__________________________________________" << endl;

//   for (int i = 0; i < 35; ++i) {
//     tasks.AddNewTask("Ivan");
//   }
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//   cout << "__________________________________________" << endl;

//   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 39);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//   cout << "__________________________________________" << endl;

//   return 0;
// }


int main() {
  TeamTasks tasks;
  // tasks.AddNewTask("Ilia");
  for (int i = 0; i < 10; ++i) {
    tasks.AddNewTask("Ivan");
  }
  // cout << "Ilia's tasks: ";
  // PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 10);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  cout << "__________________________________________" << endl;
  
  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 10);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  cout << "__________________________________________" << endl;

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 10);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  cout << "__________________________________________1" << endl;

  for (int i = 0; i < 10; ++i) {
    tasks.AddNewTask("Ivan");
  }

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 10);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  cout << "__________________________________________1" << endl;

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 10);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  cout << "__________________________________________1" << endl;

  for (int i = 0; i < 10; ++i) {
    tasks.AddNewTask("Ivan");
  }

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 10);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  cout << "__________________________________________1" << endl;

  for (int i = 0; i < 10; ++i) {
    tasks.AddNewTask("Ivan");
  }
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  cout << "__________________________________________1" << endl;

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 31);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  cout << "__________________________________________1" << endl;

  return 0;
}

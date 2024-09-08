
# Task scheduler
## 1 Introduction
### 1.1 Purpose
From balancing school to extracurricular activities, students live busy lives. As students, we feel this in our day to day and decided to do something about it. This project creates a simple, intuitive way for tasks to be scheduled and displayed. 


### 1.2 Target Audience
This program is not only practical for students, but also for working professionals in their everyday life. 

## 2 Installation/Quick Start Guide
  In order to use this program you must:
  1. Download all files in the github repository
  2. Run 
  > g++ src/main.cpp src/Grocery.cpp src/School.cpp src/Social.cpp src/Task.cpp src/TaskManager.cpp src/Work.cpp -o taskManager 
  in the terminal
  3. Run 
  > ./taskManager 
  in the terminal.

## 3 Demonstration
### 3.1 Features and Functionality
Input/Output of Project:
    Input: Numbers based on instructions
        1) Add task
        2) Delete task
        3) Edit task
        4) Undo last operation
        5) Display all tasks(Day, month, all)
    Output: outputs task assigned to specific numbers

Features of Project:
    1)Create task - title, optional: description, tag (make an option to create your own tag), priority of the tasks, optional: duration, due date, completion (add-on of delete task, prints completed when done)
    2)Create a task list where each list includes multiple tasks (subtasks within the main task)
    3)Display (displays the tasks when prompted, by day, month, all)
    4)Edit (edits the tasks, prompts for options to move priority, delete, change date, etc etc.
    5)Delete tasks and task lists. Will also undo the operation

### 3.2 Visual Demonstration
  All Inputs: https://github.com/cs100/final-project-leetcodelemons/blob/215917f52289b1a04cf66cacbea3c9ba1896aa5a/inputs.png
 
  Output of addTask: https://github.com/cs100/final-project-leetcodelemons/blob/215917f52289b1a04cf66cacbea3c9ba1896aa5a/addTask.png
 
  Output of delete task: https://github.com/cs100/final-project-leetcodelemons/blob/215917f52289b1a04cf66cacbea3c9ba1896aa5a/deleteTask.png
 
  Output of editTask: https://github.com/cs100/final-project-leetcodelemons/blob/215917f52289b1a04cf66cacbea3c9ba1896aa5a/editTask.png

  Output of Change Priority: https://github.com/cs100/final-project-leetcodelemons/blob/215917f52289b1a04cf66cacbea3c9ba1896aa5a/changePriority.png
  
  Output of Display Chosen: https://github.com/cs100/final-project-leetcodelemons/blob/215917f52289b1a04cf66cacbea3c9ba1896aa5a/displayChosen.png
  
  Output of quit: https://github.com/cs100/final-project-leetcodelemons/blob/215917f52289b1a04cf66cacbea3c9ba1896aa5a/quit.png

## 3.3 Class Diagram
https://github.com/cs100/final-project-leetcodelemons/blob/320205f99faa11ef80717345a59752950df496cf/UML%20Diagram.drawio%20(1).png
 
The task manager class is composed of the task class. The task manager contains a vector of tasks. In the class derived from task manager named “task” we use the composition arrow to link the two classes. This is because of its nature being having a strong ownership between 2 classes when one class is a part of another. 

Explaining the functions:
addTask - adds a task to the Task vector.

deleteTask - deletes the specified task corresponding to the task name inputted as string, then shift up the rest of the indices if needed.

editTask - enter the name of the task you want to change, you are then prompted for what you want to change within the editTask function, and it will change the corresponding values

displayAll - prints out all of the current tasks within the vector (output function)

displayTillDate - displays all the tasks up to a certain date (in order)

outputSpecTask - outputs a specific task, when you enter the name of the task you want to display

changePriority - changes the priority of a task.

 First off, before making any changes we had only two classes, which was a task maker class and a task manager class, but it was way too broad and we had noticed we could add new classes for separate tasks types, and from that we also noticed that they all contain similar functions. We concluded that we should use the Single-responsibility principle (SRP) to tackle this redundancy, so we are TaskManager class to handle the overall functions of the tasks and created separate classes inheriting from the base class tast that are built off that base class but contain their own separate task types and unique features. These changes helped give us more ideas on how we could expand and improve our task project.
 
We created subclasses to create types for tasks ex. SCHOOL, SOCIAL, GROCERY, and WORK. By dynamically casting these functions, we were able to allow for the user to get more options when creating tasks.
 
SCHOOL: By adding the type school, we allowed the user to label school related tasks with SCHOOL, which gave them the ability to add a professor, a subject, a room number, and a duration period.

SOCIAL: By adding the type social, we allow the user to label social related tasks with SOCIAL, which gives the ability to add guests to a guest list, remove them, and enter a duration of a planned social event.

GROCERY: By adding the type grocery, we allow the user to label tasks related to groceries with GROCERY, which gives the ability to add items to a grocery list, and remove them.

WORK: By adding the type work, we allowed for the user to label tasks related to work with WORK, this gave the ability to add a time for work shifts, a time for designated breaks, and also a vacation time.
 
 
## 4 Testing
  This program was tested using the C++ googletest suite.
  
## 5 Contributing
Authors: [Lillian Xiao](https://github.com/Tokkia)
Authors: [Sean Chang](https://github.com/PeachesSmasher)
Authors: [William Dang](https://github.com/williamDini)
Authors: [Shawn Hwang](https://github.com/ShawnHwang1)

## 6 Contact
Email: lillian.xiao.official@gmail.com



 
 

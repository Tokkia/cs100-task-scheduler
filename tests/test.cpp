#include "gtest/gtest.h"
#include "../header/Grocery.h"
#include "../header/School.h"
#include "../header/Social.h"
#include "../header/Task.h"
#include "../header/TaskManager.h"
#include "../header/Work.h"

TEST(testConstructor, testConstrSetGetSchool) {
    School* obj = new School("CS189", "CS189 class", 0, "3/16", "SCHOOL", "McHonn", 102, "Computer Science", 80);  
    EXPECT_EQ(obj->getProfessor(), "McHonn");
    EXPECT_EQ(obj->getDuration(), 80);
    obj->setSubject("NOT CS!");
    EXPECT_EQ(obj->getSubject(), "NOT CS!");
}

TEST(testConstructor, testConstrGetSocial) {
    Social* obj = new Social("PARTY!!!!", "My Birthday Party, hosted on the 8th of april!", 2, "4/8", "SOCIAL", 600);
    EXPECT_EQ(obj->getDuration(), 600);
}

//grocery has no new variables, cannot test constructor this way!

TEST(testConstructor, testConstrSetGetWork) {
    Work* obj = new Work("BurgerIM", "Information about my work", 0, "4/13", "WORK", 660, 30.0, 20);
    EXPECT_EQ(obj->getVacation(), 20);
    EXPECT_EQ(obj->getBreak(), 30.0);
    obj->setShiftLength(670);
    EXPECT_EQ(obj->getShiftLength(), 670);
}


TEST(testSocial, testAddGuest) {
    Social* obj = new Social("PARTY!!!!", "My Birthday Party, hosted on the 8th of april!", 2, "4/8", "SOCIAL", 600);
    obj->addGuest("Shean");
    obj->addGuest("William");
    EXPECT_EQ(obj->getGuest(0), "Shean");
}

TEST(testSocial, testDelGuest) {
    Social* obj = new Social("PARTY!!!!", "My Birthday Party, hosted on the 8th of april!", 2, "4/8", "SOCIAL", 600);
    obj->addGuest("Shean");
    obj->addGuest("William");
    EXPECT_EQ(obj->getGuest(0), "Shean");
}


TEST(testGrocery, testAddItem) {
    Grocery* obj = new Grocery("Trader Joes Trip!", "buy groceries at TJ", 0, "3/17", "GROCERY");
    obj->addItem("carrot");
    obj->addItem("potato");
    EXPECT_EQ(obj->getItem(0), "carrot");
}

TEST(testGrocery, testDeleteItem) {
    Grocery* obj = new Grocery("Trader Joes Trip!", "buy groceries at TJ", 0, "3/17", "GROCERY");
    obj->addItem("carrot");
    obj->addItem("potato");
    obj->delItem("carrot");
    EXPECT_EQ(obj->getItem(0), "potato");
}


TEST(testTaskManager, testAddTask) {
    TaskManager taskNum;
    Grocery* obj = new Grocery("Trader Joes Trip!", "buy groceries at TJ", 0, "3/17", "GROCERY");
    School* obj1 = new School("CS189", "CS189 class", 0, "3/16", "SCHOOL", "McHonn", 102, "Computer Science", 80); 
    taskNum.addTask(obj);
    taskNum.addTask(obj1);
    EXPECT_EQ(taskNum.find(0)->getTaskName(), "Trader Joes Trip!");
    EXPECT_EQ(taskNum.size(), 2);
}

// TEST(testTaskManager, testPrioSort) {
//     TaskManager taskNum;
//     School* obj = new School("CS189", "CS189 class", 1, "3/16", "SCHOOL", "McHonn", 102, "Computer Science", 80);
//     Social* obj1 = new Social("PARTY!!!!", "My Birthday Party, hosted on the 8th of april!", 0, "4/8", "SOCIAL", 600);
//     taskNum.addTask(obj);
//     taskNum.addTask(obj1);
//     taskNum.prioritySort();
//     EXPECT_EQ(taskNum.find(0)->getTaskName(), "PARTY!!!!");
// }

TEST(testTaskManager, testDeleteTask) {
    TaskManager taskNum;
    School* obj = new School("CS189", "CS189 class", 0, "3/16", "SCHOOL", "McHonn", 102, "Computer Science", 80);  
    taskNum.addTask(obj);
    EXPECT_EQ(taskNum.size(), 1);
    taskNum.deleteTask(0);
    EXPECT_EQ(taskNum.size(), 0);
}

TEST(testTaskManager, testEditTask) {
    TaskManager taskNum;
    Work* obj = new Work("BurgerIM", "Information about my work", 0, "4/13", "WORK", 660, 30.0, 20);
    taskNum.addTask(obj);
    taskNum.editTask(0);
    EXPECT_EQ(dynamic_cast<Work*>(taskNum.find(0))->getBreak(), 2.0);
}

TEST(testTaskManager, testChangePriority) {
    TaskManager taskNum;
    School* obj = new School("CS189", "CS189 class", 0, "3/16", "SCHOOL", "McHonn", 102, "Computer Science", 80);  
    Work* obj1 = new Work("BurgerIM", "Information about my work", 1, "4/13", "WORK", 660, 30.0, 20);
    Grocery* obj2 = new Grocery("Trader Joes Trip!", "buy groceries at TJ", 2, "3/17", "GROCERY");
    taskNum.addTask(obj);
    taskNum.addTask(obj1);
    taskNum.addTask(obj2);
    taskNum.changePriority(0, 1);
    EXPECT_EQ(taskNum.find(0)->getTaskName(), "BurgerIM");
}
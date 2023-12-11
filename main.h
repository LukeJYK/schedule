#include<iostream>
// declaare a struct called task
// task type can be invalid/local/cloud

enum task_type { invalid = 0, local, cloud};
struct task {
	int id; 
	bool ct;  // judge whether the task is a cloud task
	double pri; // 
	int ftl;  
	int ftws;
	int ftc;  
	int ftwr;  
	int rtl; // the earlist  time that the task can start in local core
	int rtws; // the earlist  time that the task can start in sending
	int rtc;  // the earlist  time that the task can start in cloud
	int rtwr; //the earlist  time that the task can start in receiving
	int ST; // the task's actual start time
	int core; // illustrate which channel the task operate (local core = 0,1,2, cloud=3)
	bool exit;  //whether it is an exit task
	bool entry;  // whether it is an entry task
	int ready1;
	int ready2;
};
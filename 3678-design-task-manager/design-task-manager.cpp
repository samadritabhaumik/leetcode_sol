class TaskManager {
    struct TaskData {
        int userId;
        int taskId;
        long long priority;
        bool removed;
        TaskData(int u, int t, long long p):userId(u),taskId(t),priority(p),removed(false){}
         };

    struct Compare {
        bool operator()(TaskData* a, TaskData* b) const {
            if (a->priority != b->priority) {
                return a->priority < b->priority; 
            }
            return a->taskId < b->taskId; 
        }
    };

    priority_queue<TaskData*, vector<TaskData*>, Compare> tasksQueue;
    unordered_map<int, TaskData*> tasksMap;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& triple : tasks) {
            add(triple[0], triple[1], triple[2]);
        }
    }

    void add(int userId, int taskId, long long priority) {
        TaskData* data = new TaskData(userId, taskId, priority);
        tasksMap[taskId] = data;
        tasksQueue.push(data);
    }

    void edit(int taskId, long long newPriority) {
        if (tasksMap.count(taskId)) {
            TaskData* oldData = tasksMap[taskId];
            oldData->removed = true;
            TaskData* newData = new TaskData(oldData->userId, oldData->taskId, newPriority);
            tasksMap[taskId] = newData;
            tasksQueue.push(newData);
        }
    }

    void rmv(int taskId) {
        if (tasksMap.count(taskId)) {
            TaskData* data = tasksMap[taskId];
            data->removed = true;
            tasksMap.erase(taskId);
        }
    }

    int execTop() {
        while (!tasksQueue.empty()) {
            TaskData* top = tasksQueue.top();
            if (!top->removed) {
                tasksQueue.pop();
                tasksMap.erase(top->taskId);
                top->removed = true;
                return top->userId;
            }
            tasksQueue.pop();
        }
        return -1;
    }
};


/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
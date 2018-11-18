def first_come(data, no_of_processes, previous):
    index=0
    flag=False
    for i in range(no_of_processes-1):
            if data[i+1].get("Arrival") < data[index].get("Arrival"):
                if len(previous)>=0:
                    for j in range(len(previous)):
                        if i+1 == previous[j]:
                            flag=True
                if not flag:
                    index=i+1
            elif data[index].get("Arrival") < data[i+1].get("Arrival") and index not in previous:
                index=index
            else:
                index=i+1
            flag=False
    return index

def check_new_process(data, no_of_processes, index, count):
    if data[index+1].get("Arrival")<=count:
        return True
    else:
        return False
def check_count_new(data, no_of_processes, index):
    count=0
    for i in range(no_of_processes):
        if(data[i].get("Arrival")==data[index].get("Arrival")):
            count=count+1

def short_time_remaining_first(data, index, no_of_processes, count, previous):
    count1=0
    index1=0
    arrays=[]

    while count1!=count:
        if check_new_process(data, no_of_processes, index1+1, count1)==False]:
            print("-", index1)
            count1=count1+1
            data[index1].get("Cpu")=data[index1].get("Cpu")-1
        else:
            arrays.append(data[index1])
            count_new=check_count_new(data, no_of_processes, index+1)

    
# main code
data=[]
file=open("myFile.txt", "r")

no_of_processes=int(file.readline())
print(no_of_processes)
i=0
while i < no_of_processes:
    data.append({"Arrival":int(file.readline()), "Cpu":int(file.readline()), "Input":int(file.readline())})
    i=i+1
file.close()
for i in range(len(data)):
    print(data[i])
##index=short_job_index(data, no_of_processes,0)
##print(index)
index=[]
for i in range(no_of_processes):
    index.append(first_come(data, no_of_processes, index))
print(index)
##count=0
##for i in range(no_of_processes):
##    start_time=count
##    print("StartExecutionProcess:", index[i])
##    for j in range(data[index[i]].get("Cpu")):
##        print("-")
##        count=count+1
##    print("| EndExecutionProcess:", index[i])
##    print("Waiting time = ", start_time-0)
##    print("TurnAroundTime = " , count-0)
##print(count)

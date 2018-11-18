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
count=0
for i in range(no_of_processes):
    start_time=count
    print("StartExecutionProcess ArrivalTime:", data[index[i]].get("Arrival"))
    for j in range(data[index[i]].get("Cpu")):
        print("-")
        count=count+1
    print("| EndExecutionProcess ArrivalTime:", data[index[i]].get("Arrival"))
    print("Waiting time = ", start_time-data[index[i]].get("Arrival"))
    print("TurnAroundTime = " , count-data[index[i]].get("Arrival"))
#print(count)

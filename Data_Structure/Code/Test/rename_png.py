import os
base_path = "/Users/martin/Downloads/pic"
for path in os.listdir(base_path):
    # print(path)
    if path[:3] == "IMG":
        old_path = os.path.join(base_path, path)
        num = int(path[4:8]) - 6418
        new_name = str(num)
        if (num < 10):
            new_name = "0"+str(num)
        new_name = "mz" + new_name + ".jpg"
        new_path = os.path.join(base_path, new_name,)
        os.rename(old_path, new_path)
        print(old_path, " ", new_path)

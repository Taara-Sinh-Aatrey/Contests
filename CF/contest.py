# import json
# import urllib.request
# from bs4 import BeautifulSoup
# import os
# import subprocess
# import sys
# import platform

# # Run this file as "python contest.py https://codeforces.com/contest/contest_id contest_folder_name"

# if(len(sys.argv) < 3):
# 	print('Run this file as "python contest.py contest_link contest_folder_name"')
# 	exit()
# else:
# 	url = sys.argv[1]
# 	contest_id = sys.argv[2]

# if(url.find('https://codeforces.com/contest') == -1 and url.find('https://codeforces.com/gym') == -1):
# 	print("Invalid Url")
# 	exit()
# else:
# 	page = urllib.request.urlopen(url, timeout=20)
# soup = BeautifulSoup(page, features = "html.parser")

# data = []

# table = soup.find('table', attrs={'class':'problems'})

# rows = table.find_all('tr')
# for row in rows:
# 	cols = row.find_all('td')
# 	cols = [ele.text.strip() for ele in cols]
# 	data.append([ele for ele in cols if ele])

# problems = []
# for i in range(len(data)):
# 	if(len(data[i])>0):
# 		problems.append(data[i][0])

# print("Problem Names :", problems, "\n")

# path = contest_id
# parent_dir = os.getcwd()

# path = os.path.join(parent_dir,path)
# if not os.path.exists(path):
# 	os.mkdir(path)
# 	print("Created folder", contest_id, "\n")

# # open folder in sublime
# subprocess.run(["subl", "-a", path], stdout=subprocess.DEVNULL)
	
# # open friends standings
# x = url + '/standings/friends/true'
# if platform.system() == 'Linux':
# 	subprocess.run(["google-chrome", x], stdout=subprocess.DEVNULL)
# else:
# 	os.system("start chrome " + x)
	
# # open dashboard
# if platform.system() == 'Linux':
# 	subprocess.run(["google-chrome", url], stdout=subprocess.DEVNULL)
# else:
# 	os.system("start chrome " + url)
	
# # open problem A
# x = url + "/problem/A"
# if platform.system() == 'Linux':
# 	subprocess.run(["google-chrome", x], stdout=subprocess.DEVNULL)
# else:
# 	os.system("start chrome " + x)
	
# for problem in problems:
# 	problem_path = os.path.join(path,problem)
# 	with open(problem_path+".cpp", "a") as sec:
# 		pass
# 	print("created file", problem+".cpp")
# 	problem_url = " " + url + "/problem/" + problem + " \"";
# 	os.system('python automate.py ' + problem + problem_url + problem_path + "\"")
# 	print("")
import json
import urllib.request
from bs4 import BeautifulSoup
import os
import subprocess
import sys
import platform

# Run this file as "python contest.py"

print('Enter folder name')
path = input()

gym = 0
print('Enter 0 for regular contest, 1 for a gym contest?')
gym = int(input())

print('Enter contest id')
contest_id = input()

if gym == 0:
	url = 'https://codeforces.com/contest/' + contest_id
else:
	url = 'https://codeforces.com/gym/' + contest_id

page = urllib.request.urlopen(url, timeout=20)
soup = BeautifulSoup(page, features = "html.parser")

data = []

table = soup.find('table', attrs={'class':'problems'})

rows = table.find_all('tr')
for row in rows:
    cols = row.find_all('td')
    cols = [ele.text.strip() for ele in cols]
    data.append([ele for ele in cols if ele])

problems = []
for i in range(len(data)):
    if(len(data[i])>0):
        problems.append(data[i][0])

print("Problem Names :", problems, "\n")

parent_dir = os.getcwd()

path = os.path.join(parent_dir,path)
if not os.path.exists(path):
    os.mkdir(path)
    print("Created folder", contest_id, "\n")

# open folder in sublime
subprocess.run(["subl", "-a", path], stdout=subprocess.DEVNULL)
    
# open friends standings
x = url + '/standings/friends/true'
if platform.system() == 'Linux':
    subprocess.run(["google-chrome", x], stdout=subprocess.DEVNULL)
else:
    os.system("start chrome " + x)
    
# open dashboard
if platform.system() == 'Linux':
    subprocess.run(["google-chrome", url], stdout=subprocess.DEVNULL)
else:
    os.system("start chrome " + url)
    
# open problem A
x = url + "/problem/A"
if platform.system() == 'Linux':
    subprocess.run(["google-chrome", x], stdout=subprocess.DEVNULL)
else:
    os.system("start chrome " + x)
    
for problem in problems:
    problem_path = os.path.join(path,problem)
    with open(problem_path+".cpp", "a") as sec:
        pass
    print("created file", problem+".cpp")
    problem_url = " " + url + "/problem/" + problem + " \"";
    os.system('python automate.py ' + problem + problem_url + problem_path + "\"")
    print("")
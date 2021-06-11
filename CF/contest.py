import json
import urllib.request
from bs4 import BeautifulSoup
import os
import subprocess
import sys

# Run this file as "python contest.py https://codeforces.com/contest/contest_id contest_folder_name"

if(len(sys.argv) < 3):
	print('Run this file as "python contest.py contest_link contest_folder_name"')
	exit()
else:
	url = sys.argv[1]
	contest_id = sys.argv[2]

if(url.find('https://codeforces.com/contest') == -1 and url.find('https://codeforces.com/gym') == -1):
	print("Invalid Url")
	exit()
else:
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

path = contest_id
parent_dir = os.getcwd()

path = os.path.join(parent_dir,path)
if not os.path.exists(path):
	os.mkdir(path)
	print("Created folder", contest_id, "\n")

# open folder in sublime
subprocess.run(["subl", "-a", path], stdout=subprocess.DEVNULL)

# open friends standings
x = url + '/standings/friends/true'
subprocess.run(["google-chrome", x], stdout=subprocess.DEVNULL)

# open dashboard
subprocess.run(["google-chrome", url], stdout=subprocess.DEVNULL)

# open problem A
x = url + "/problem/A"
subprocess.run(["google-chrome", x], stdout=subprocess.DEVNULL)

for problem in problems:
	problem_path = os.path.join(path,problem)
	with open(problem_path+".cpp", "a") as sec:
		pass
	print("created file", problem+".cpp")
	problem_url = " " + url + "/problem/" + problem + " \"";
	os.system('python automate.py ' + problem + problem_url + problem_path + "\"")
	print("")
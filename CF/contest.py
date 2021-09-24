import json
import urllib.request
from bs4 import BeautifulSoup
import os
import subprocess
import sys
import platform

def ParseProblem(problem, url, filename):
    filename += ".cpp__tests"
    try:
        page = urllib.request.urlopen(url, timeout=20)
    except:
        print("Couldn't parse", problem+".cpp__tests")
        exit()
    soup = BeautifulSoup(page, features = "html.parser")
    x = soup.body.find_all('div', attrs={'class' : 'input'})
    y = soup.body.find_all('div', attrs={'class' : 'output'})
    res = ""
    out = ""
    for elements in x:
        t = elements.text
        if t[5] != '\n':
            t = t[:5] + '\n' + t[5:]
        res += t
    for elements in y:
        t = elements.text
        if t[6] != '\n':
            t = t[:6] + '\n' + t[6:]
        out += t
    res = res.split('Input\n')
    out = out.split('Output\n')
    res.remove("")
    out.remove("")
    out = [elements.strip() for elements in out]
    correct = []
    for elements in  out:
        correct.append([elements])
    final = []
    sz = len(res)
    for i in range(sz):
        dic = {
            "test" : res[i],
            "correct_answers" : correct[i]
        }
        final.append(dic) 
    with open(filename, "w") as outfile: 
        outfile.write(json.dumps(final)) 
    print("Parsed prolem", problem, "testcases")
    
gym = 0
if len(sys.argv) > 2:
    print('Invalid option')
    exit()
elif len(sys.argv) == 2:
    gym = int(sys.argv[1])

if gym != 0 and gym != 1:
    print('Invalid option')
    exit()

path = input('Enter folder name : ')
contest_id = input('Enter contest id : ')
if gym == 0:
	url = 'https://codeforces.com/contest/' + contest_id
elif gym == 1:
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
    
# open firstproblem
x = url + "/problem/" + problems[0]
if platform.system() == 'Linux':
    subprocess.run(["google-chrome", x], stdout=subprocess.DEVNULL)
else:
    os.system("start chrome " + x)
    
for problem in problems:
    problem_path = os.path.join(path,problem)
    with open(problem_path+".cpp", "a") as sec:
        pass
    print("created file", problem+".cpp")
    problem_url = url + "/problem/" + problem
    ParseProblem(problem, problem_url, problem_path)
    print("")
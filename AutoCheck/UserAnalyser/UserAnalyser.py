contest_num_log = open("../SampleMemoriser/contest_num_log.txt",'r')
for line in contest_num_log.readlines():
	contest_num = line.rstrip('\n')
	break
contest_num_log.close()

usernames_full=set(["p-adic"])

def SeparateByAngle(s):
	s = s.replace("<br>","")
	s = s.replace("<br/>","")
	s = s.replace("<br />","")
	s = s.replace("</br>","")
	s = s.replace("\n","")
	return[t.split('<')[0]for t in s.split('>')]

two_byte_message = open("two_byte_message.txt",'r')
message_list = [line.rstrip('\n')for line in two_byte_message.readlines()]
two_byte_message.close()
init = True

import requests
from bs4 import BeautifulSoup
print("https://yukicoder.me/contests/" + str(contest_num),message_list[0])
contest_table_page_url = "https://yukicoder.me/contests/" + str(contest_num) + "/table"

while True:
	contest_table_page = BeautifulSoup(requests.get(contest_table_page_url).text,'html.parser')
	problem_count = 0
	problem_names = []
	usernames=usernames_full.copy()

	if problem_count == 0:
		for th_tag in contest_table_page.find_all("th"):
			temp = str(th_tag)
			if temp.find("/problems/") != -1:
				temp = SeparateByAngle(temp)[2].split()
				problem_count += 1
				problem_names += [temp[0]+" "+temp[1][:7]+" "+temp[1][7:]]

	order = "0"
	username = ""
	for td_tag in contest_table_page.find_all("td"):
		temp = SeparateByAngle(str(td_tag))
		if order != "0" and username == "":
			assert len(temp)>3
			username = temp[-3].split()[0]
			if username in usernames:
				usernames.remove(username)
				print(username+(""if username=="p-adic"else message_list[1]),order+message_list[2])
				problem_num = 0
				continue
			else:order,username = "0",""
		if order == "0":
			if len(temp)>4 and '0'<=temp[4][3:-2]<='999':order = temp[4][3:-2]
			elif len(temp)>2 and '0'<=temp[2][3:-2]<='999':order = temp[2][3:-2]
			continue
		if temp[2] == "0":
			assert len(temp)in[5,7]
			if len(temp) == 5:temp = temp[:3]+["","(0)","--:--:--","-","--th"]+temp[4:]
			else:temp = temp[:5]+["--:--:--","-","--th"]+temp[6:]
		else:
			assert len(temp)in[7,9]
			if len(temp) == 7:
				if temp[3].split()[0] == "-":temp[3] = "--:--:--"
				temp = temp[:3]+["","(0)"]+temp[3:]
		print(problem_names[problem_num].split()[0]+": "+("not AC"if temp[2]=="0"else"    AC"),temp[4],temp[5].split()[0],temp[7].split()[0],sep=",")
		problem_num += 1
		if problem_num == problem_count:
			print("")
			order,username = "0",""
	for username in usernames:
		if username != "p-adic":print(username,message_list[3])
	print(message_list[4])
	print(message_list[5])
	finish = input()
	if finish != "n":break

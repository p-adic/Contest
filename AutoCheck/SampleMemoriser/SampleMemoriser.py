wait = True
#wait = False
contest_num = None

import datetime
now = datetime.datetime.now()
year = now.year
month = now.month
day = now.day
date = str(year) + "-" + str(100+month)[1:] + "-" + str(100+day)[1:]

two_byte_message = open("two_byte_message.txt",'r')
message_list = [line.rstrip('\n')for line in two_byte_message.readlines()]
two_byte_message.close()

import requests
from bs4 import BeautifulSoup
if wait:
	contest_list_page_url = "https://yukicoder.me/contests"
	contest_list_page = BeautifulSoup(requests.get(contest_list_page_url).text,'html.parser')
	for a_tag in contest_list_page.find_all("a"):
		temp = str(a_tag)
		if temp[:19] != "<a href=\"/contests/":continue
		temp = temp.split('"')[1].split('/')[-1]
		if temp == "calendar":continue
		contest_num = temp
		break
	for td_tag in contest_list_page.find_all("td"):
		temp = td_tag.text.split()
		if len(temp) < 1 or temp[0] != date:continue
		assert len(temp) == 5 , temp
		temp = temp[2].split(':')
		assert len(temp) == 3
		start_hour = int(temp[0])
		start_minute = int(temp[1])
		start_second = int(temp[2][:2])
		break
	contest_num_log = open("contest_num_log.txt",'w')
	contest_num_log.write(contest_num + "\n")
	contest_num_log.close()
	print(message_list[0],contest_num,message_list[1],str(start_hour),message_list[2],str(start_minute),message_list[3],str(start_second),message_list[4])
else:
	assert(contest_num is not None)

init = True
while wait:
	now = datetime.datetime.now()
	if start_hour <= now.hour and start_minute <= now.minute and 5 <= now.second:break
	elif init:
		init = False
		print(message_list[5],str(now.hour),message_list[2],str(now.minute),message_list[3],str(now.second),message_list[4])
		print(message_list[6],str(start_hour),message_list[2],str(start_minute),message_list[3],str(start_second + 5),message_list[4])

print("https://yukicoder.me/contests/" + contest_num,message_list[6])
contest_table_page_url = contest_list_page_url + "/" + contest_num + "/table"
contest_table_page = BeautifulSoup(requests.get(contest_table_page_url).text,'html.parser')
problem_order_list = []
register_log = open("Sample/register_log.txt",'w')
for a_tag in contest_table_page.find_all("a"):
	temp = str(a_tag)
	if temp[:22] != "<a href=\"/problems/no/":continue
	temp = temp.split('\"')[1]
	problem_order = contest_table_page.find("a",{"href":temp}).text.split()[0]
	problem_order_list += [problem_order]
	problem_page_url = "https://yukicoder.me" + temp
	problem_page = BeautifulSoup(requests.get(problem_page_url).text,'html.parser')
	count = 100
	count_list = []
	registered = True
	for sample in problem_page.find_all("div",{"class":"sample"}):
		count += 1
		temp = str(sample).split("<pre>")
		input_file = open("Sample/" + problem_order + "/input/sample" + str(count)[1:] + ".txt",'w')
		output_file = open("Sample/" + problem_order + "/output/sample" + str(count)[1:] + ".txt",'w')
		registered &= len(temp) == 3
		if len(temp) < 3:
			print(problem_order,message_list[7],str(count%100),message_list[8])
		else:
			if len(temp) != 3:print(problem_order,message_list[7],str(count%100),message_list[9])
			for i,file in zip([1,2],[input_file,output_file]):
				temp[i] = temp[i].split("</pre>")[0]
				temp[i] = temp[i].split("<code>")[-1]
				temp[i] = temp[i].split("</code>")[0]
				for br in ["<br>","</br>","<br/>"]:temp[i] = "\n".join(temp[i].split(br))
				if temp[i] and temp[i][0] == '\n':temp[i] = temp[i][1:]
				if temp[i][-1] != '\n':temp[i] += '\n'
				file.write(temp[i])
				file.close()
		count_list += [str(count)[1:]+'\n']
	count_file = open("Sample/" + problem_order + "/count.txt",'w')
	count_file.write(str(len(count_list)) + '\n')
	for valid_count in count_list:count_file.write(valid_count)
	count_file.close()
	if registered:register_log.write(problem_order+'\n')
	print(problem_order,message_list[10],len(count_list),message_list[11])
problem_order_file = open("Sample/problem_order.txt",'w')
problem_order_file.write(str(len(problem_order_list)) + '\n')
for valid_problem_order in problem_order_list:problem_order_file.write(valid_problem_order)
problem_order_file.close()
print(message_list[12])
while True:
	print(message_list[13])
	finish = input()
	if finish == "y":break

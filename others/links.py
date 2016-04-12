# Author : moranzcw
# Date   : 2016-04-13
# This script is used to generate a list of links from leetcode.com

import os
import re
from urllib import request
from bs4 import BeautifulSoup

response = request.urlopen('https://leetcode.com/problemset/algorithms/') 
html_content = response.read()
soup = BeautifulSoup(html_content, "html.parser")

problem_tag_list = soup.find_all('tr')

for each in problem_tag_list:
	
	problem_num_tag = each.find('td',text = re.compile("^\d+$"))
	if problem_num_tag:
		problem_num = problem_num_tag.get_text()
	else:
		continue

	problem_tag = each.find('a',href = True)
	if problem_tag:
		problem_title = problem_tag.get_text()
		problem_link = "https://leetcode.com/" + problem_tag['href']
	else:
		continue

	print("| " + problem_num + " | [" + problem_title + "](" + problem_link + ") |")

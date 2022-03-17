import requests
from bs4 import BeautifulSoup

headers = {'user-agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.99 Safari/537.36'}

def Get_html(url):
    response = requests.get(url,headers=headers)
    if response.status_code==200:
        Parse_html(response.text)
    else:
        print("ERROR:",response.status_code)

def Parse_html(content,'lxml')
:
    pass

if __name__=='__main__':
    url = 'https://www.bbc.co.uk/news/uk-england-essex-60440429'
    Get_html(url)
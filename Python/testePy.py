import urllib.request

req = urllib.request.Request(url='http://172.246.16.27/helder/retorna.php',
                       data=b'This data is passed to stdin of the CGI')
f = urllib.request.urlopen(req)
print(f.read().decode('utf-8'))

import urllib.request
import sys

def main():

    value = sys.argv[1]
    pullURL = "http://172.246.16.27/helder/pullTemperature.php/?temperatura=%s" % value
    getURL = "http://172.246.16.27/helder/getAjuste.txt"
    
    req = urllib.request.Request(url=pullURL, data=b'This data is passed to stdin of the CGI')
    f = urllib.request.urlopen(req)

    print(f.read().decode('utf-8'))

    req = urllib.request.Request(url=getURL, data=b'This data is passed to stdin of the CGI')
    ajuste = urllib.request.urlopen(req)

    
    
    file = open('sensor.txt','w')
    file.write(ajuste.read().decode('utf-8'))
        
main()

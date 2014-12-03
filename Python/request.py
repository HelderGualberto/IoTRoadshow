import urllib2
import sys

def main():

    value = sys.argv[1]
    pullURL = "http://172.246.16.27/helder/pullTemperature.php/?temperatura=%s" % value
    getURL = "http://172.246.16.27/helder/getAjuste.txt"
    
    req = urllib2.Request(url=pullURL, data=b'This data is passed to stdin of the CGI')
    f = urllib2.urlopen(req)

    print f.read().decode('utf-8')

    req = urllib2.Request(url=getURL, data=b'This data is passed to stdin of the CGI')
    ajuste = urllib2.urlopen(req)

    
    
    arquivo = open('acontrol/sensor.txt','w')
    arquivo.write(ajuste.read().decode('utf-8'))
    arquivo.close()
        
main()

sys.exit(0)

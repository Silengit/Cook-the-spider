import re
import requests


class BFilter:
    RSHashList = [0]*2500
    JSHashlist = [0]*2500
    PJWHashlist = [0]*2500
    ELFHashlist = [0]*2500
    BKDRHashlist = [0]*2500
    SDBMHashlist = [0]*2500
    DJBHashlist = [0]*2500
    DEKHashlist = [0]*2500
    ctr = 0

    def RSHash(str):
        b = 378551
        a = 63689
        hash = 0
        i = 0
        while (i < len(str)):
            hash = hash * a + ord(str[i])
            a = a * b
            i += 1
        return hash

    def JSHash(str):
        hash = 1315423911
        i = 0
        while (i < len(str)):
            hash ^= ((hash << 5) +  ord(str[i]) + (hash >> 2));
            i += 1
        return hash

    def PJWHash(str):
        BitsInUnsignedInt = (4 * 8)
        ThreeQuarters = int((BitsInUnsignedInt * 3) / 4)
        OneEighth = int(BitsInUnsignedInt / 8)
        HighBits = (0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth)
        hash = 0
        test = 0
        i = 0
        while (i < len(str)):
            hash = (hash << OneEighth) +  ord(str[i])
            if (hash & HighBits != 0):
                test = hash & HighBits
                hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits))
            i += 1
        return hash

    def ELFHash(str):
        hash = 0
        x = 0
        i = 0
        while (i < len(str)):
            hash = (hash << 4) +  ord(str[i])
            if ((hash & 0xF0000000) != 0):
                x = hash & 0xF0000000
                hash ^= (x >> 24)
            hash &= ~x
            i += 1
        return hash

    def BKDRHash(str):
        seed = 131
        hash = 0
        i = 0
        while i < len(str):
            hash = (hash * seed) +  ord(str[i])
            i += 1
        return hash

    def SDBMHash(str):
        hash = 0
        i = 0
        while i < len(str):
            hash =  ord(str[i]) + (hash << 6) + (hash << 16) - hash
            i += 1
        return hash

    def DJBHash(str):
        hash = 5381
        i = 0
        while i < len(str):
            hash = ((hash << 5) + hash) +  ord(str[i])
            i += 1
        return hash

    def DEKHash(str):
        hash = len(str)
        i = 0
        while (i < len(str)):
            hash = ((hash << 5) ^ (hash >> 27)) ^  ord(str[i])
            i += 1
        return hash

    def BF(str):
        flag = True
        if (BFilter.RSHashList[abs(BFilter.RSHash(str)) % 2500] == 0):
            flag = False
            BFilter.RSHashList[abs(BFilter.RSHash(str)) % 2500] = 1
        if (BFilter.JSHashlist[abs(BFilter.JSHash(str)) % 2500] == 0):
            flag = False
            BFilter.JSHashlist[abs(BFilter.JSHash(str)) % 2500] = 1
        if (BFilter.PJWHashlist[abs(BFilter.PJWHash(str)) % 2500] == 0):
            flag = False
            BFilter.PJWHashlist[abs(BFilter.PJWHash(str)) % 2500] = 1
        if (BFilter.ELFHashlist[abs(BFilter.ELFHash(str)) % 2500] == 0):
            flag = False
            BFilter.ELFHashlist[abs(BFilter.ELFHash(str)) % 2500] = 1
        if (BFilter.BKDRHashlist[abs(BFilter.BKDRHash(str)) % 2500] == 0):
            flag = False
            BFilter.BKDRHashlist[abs(BFilter.BKDRHash(str)) % 2500] = 1
        if (BFilter.SDBMHashlist[abs(BFilter.SDBMHash(str)) % 2500] == 0):
            flag = False
            BFilter.SDBMHashlist[abs(BFilter.SDBMHash(str)) % 2500] = 1
        if (BFilter.DJBHashlist[abs(BFilter.DJBHash(str)) % 2500] == 0):
            flag = False
            BFilter.DJBHashlist[abs(BFilter.DJBHash(str)) % 2500] = 1
        if (BFilter.DEKHashlist[abs(BFilter.DEKHash(str)) % 2500] == 0):
            flag = False
            BFilter.DEKHashlist[abs(BFilter.DEKHash(str)) % 2500] = 1
        return ~flag



#word = input("Input key word: ")
#url = 'http://image.baidu.com/search/flip?tn=baiduimage&ie=utf-8&word='+word+'&ct=201326592&v=flip'
'''
url = 'http://image.baidu.com/search/flip?tn=baiduimage&ipn=r&ct=201326592&cl=2&lm=-1&st=-1&fm=result&fr=&sf=1&fmq=1460997499750_R&pv=&ic=0&nc=1&z=&se=1&showtab=0&fb=0&width=&height=&face=0&istype=2&ie=utf-8&word=%E5%B0%8F%E9%BB%84%E4%BA%BA'
html = requests.get(url).text
# print(html)
pic_url = re.findall('"objURL":"(.*?)",', html, re.S)
web_url = re.findall('/search/.*height=0', html)



i = 0
'''
#for each in pic_url:
#    print(each)
#    try:
#        pic = requests.get(each, timeout=10)
#    except requests.exceptions.ConnectionError:
#        print('错误，当前图片无法下载')
#        continue
#    string = 'pictures\\'+str(i)+'.jpg'
#    fp = open(string, 'wb')
#    fp.write(pic.content)
#    fp.close()
#    i += 1


def Get_Picture(web_url, j):
    i = j*60
    new_html = requests.get(web_url).text
    pic_url = re.findall('"objURL":"(.*?)",', new_html, re.S)
    for each in pic_url:
        print(each)
        try:
            pic = requests.get(each, timeout=2)
        except:
            print('错误，当前图片无法下载')
            continue
        string = 'pictures\\'+str(i)+'.jpg'
        fp = open(string, 'wb')
        fp.write(pic.content)
        fp.close()
        i += 1


def Goto_Sites(web_url, j):
    new_html = requests.get(web_url).text
    new_url_behind = re.findall('/search/.*height=0', new_html)
    for each in new_url_behind:
        new_url = "http://image.baidu.com"+each
        if BFilter.BF(new_url):
            Get_Picture(new_url, j)
            BFilter.ctr += 1
            if BFilter.ctr < 1000:
                Goto_Sites(new_url, j+1)

def main():
    url = 'https://image.baidu.com/search/flip?tn=baiduimage&ipn=r&ct=201326592&cl=2&lm=-1&st=-1&fm=result&fr=&sf=1&fmq=1515033163047_R&pv=&ic=0&nc=1&z=&se=1&showtab=0&fb=0&width=&height=&face=0&istype=2&ie=utf-8&ctd=1515033163047%5E00_1349X675&word=%E5%B0%8F%E9%BB%84%E4%BA%BA'
    j = 0
    Goto_Sites(url, j)


if __name__ == '__main__':
    main()

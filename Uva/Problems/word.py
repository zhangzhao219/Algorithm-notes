#-*- coding : utf-8-*-
import os
from io import StringIO
from io import open
from pdfminer.converter import TextConverter
from pdfminer.layout import LAParams
from pdfminer.pdfinterp import PDFResourceManager, process_pdf
 
 
def read_pdf(pdf):
    # resource manager
    rsrcmgr = PDFResourceManager()
    retstr = StringIO()
    laparams = LAParams()
    # device
    device = TextConverter(rsrcmgr, retstr, laparams=laparams)
    process_pdf(rsrcmgr, device, pdf)
    device.close()
    content = retstr.getvalue()
    retstr.close()
    # 获取所有行
    lines = str(content).split('\n')
    return lines

if __name__ == '__main__':
    for i,j,k in os.walk('./'):
        path = i
        print(path)
        for kl in k:
            pathall = path +'/' + kl
            pathaim = path +'/' + kl.split('.')[0] + '.in'
            if(pathall != ".//word.py"):
                with open(pathall, "rb") as my_pdf:
                    list = read_pdf(my_pdf)
                    for i in range(len(list)):
                        if list[i] == "Sample Input" or list[i] == "Sample input"  or list[i] == "sample input"  or list[i] == "sample Input":
                            i += 1
                            while i < len(list) and list[i] != 'Sample Output':
                                if list[i] != '':
                                    with open(pathaim, 'a') as f:
                                        f.write(list[i])
                                        f.write("\n")
                                i += 1
                            break
from microbit import *
 
sun = Image('09990:90009:09990:00900:09990:')
few = Image('04040:44444:04040:00000:00000:')
cloud = Image('06060:66666:06060:00000:00000:')
broken = Image('09090:99999:09090:00000:00000:')
shower = Image('09090:99999:09090:30303:03030:')
rain = Image('07070:77777:07070:20202:02020:')
thunder = Image('90090:09009:00900:09009:90090:')
snow = Image('70707:07070:70707:07070:70707:')
mist = Image('22222:33333:22222:33333:22222:')


weather = {'01': sun, '02':few, '03': cloud, 
           '04': broken, '09': shower, '10':rain,
           '11':thunder, '13':snow, '50': mist}

while True:
    sleep(500)
    bytestring = uart.readline()
    try:
        icon = weather[(str(bytestring, 'utf-8'))[:2]]
        display.show(icon)
    except:
        pass
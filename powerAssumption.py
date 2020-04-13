#Small Python script to validate the assumption that a PWM output to a SSR will
#   provide average power proportional to the PWM duty cycle.
import math as m
import random
PWM_PERIOD=1/976.5625
def pwm(t, duty):
    
    max_duty  =255
    fractional_cycle=divmod(t,PWM_PERIOD)[1]/PWM_PERIOD
    #print(fractional_cycle,divmod(t,pwm_period)[0])
    fractional_duty=duty/max_duty
    if(fractional_cycle<fractional_duty):
        return 1
    else:
        return 0
    
def cross(last, now):
    if(last>0 and now<0):
        #print("-")
        return 1
    if(last<0 and now>0):
        #print("+")
        return 1
    return 0

def dorun(inp,duration):
    offset=random.random()*PWM_PERIOD
    drift=random.random()*.0008+1
    t = 0
    Ts=3e-5
    start = 0
    stop = 1
    Nstart = int(start/Ts)
    Nstop = int(stop/Ts)+1
    ac=-.01
    hits=0
    total=1
    for n in range(Nstart, Nstop):
        t = n*Ts
        last_ac=ac
        ac = m.sin(60*(2*m.pi)*t)
        square = pwm(t*drift+offset,inp)
        if(cross(last_ac,ac)):
            total=total+1
            if(square==1):
                hits=hits+1
                #print("Hit")
            else:
                #print("Miss")
                pass
    return [hits,total]


totalhit=0
total=0
biggestdiff=[0,0]
for i in range(0,255):
    p=i
    result = dorun(p,1000)
    percent_power=result[0]/result[1]*100
    diff=abs(percent_power-p/255*100)
    print("PWM:",p,"gives ",result[0]/result[1]*100,"% average power at",p/255*100)
    if(diff>biggestdiff[1]):
        biggestdiff[0]=p
        biggestdiff[1]=diff
    totalhit=totalhit+result[0]
    total=total+result[1]
print("Total deliverd power:",totalhit/total*100,"%",sep="")
print("Biggest percent difference:",biggestdiff[1],"% for PWM of",biggestdiff[0])

    

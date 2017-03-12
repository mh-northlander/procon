#wrt(k)
#numdot(k)
#numdot1(k)
#numdot2(["","","","",~],"1234~")

def numdot(k)
  lib = []
  ls = numdot1(k)
  for i in 0...ls.length
    lib[lib.length] = stick(ls[i])
  end
  return lib
end

def numdot1(k)
  l=[]
  s=""
  for i in 1..k
    l<<""
    s+=i.to_s
  end
  return numdot2(l,s)
end

def wrt(k)
  lib = numdot(k)
  st=""
  for i in 0...lib.length
    st+= lib[i]+"\n"
  end
  open("sample.txt","w"){|f| f.write st}
end

def stick(l)
  s=""
  for i in 0...l.length
    s+=l[i]+"."
  end
  while s[s.length-1] == "."
    s = s[0..s.length-2]
  end
  return s
end

def numdot2(l,s)#l=["","","","",""] , s="12345"
  if s.length>0
    ls=[]
    f=0
    for i in 0...l.length
      ll=l.clone
      if ll[i]==""
        f=1
      end
      ll[i]+=s[0]      
      ls+=numdot2(ll,s[1..s.length])
      if f==1
        break
      end
    end
    return ls
  else
    return [l]
  end
end

def line(k) #k:1to5
  l=["","","","",""] 
  for i in 1..k
    l[0] += i.to_s
  end
  return l 
end

def sortnum(s)
  ch=[]
  for i in 0...s.length
    ch[ch.length]=s[i]
  end
  ch = ch.sort
  ss=""
  for i in 0...ch.length
    ss+=ch[i]
  end
  return ss
end

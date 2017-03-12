#a=  shufflers1() :txt to []
#a2= 2(a)         :list of all ids&names
#l=  3(a,a2[1])   :ids of each neme (1)
#l2= 4(l)         :(2)
#t= 5(l2)        :[] to txt(1)
#t2= 6(t)        :(2)
#write(t2)

def shufflers()
  a  = shufflers1()
  a2 = shufflers2(a)
  l  = shufflers3(a,a2[1])
  l2 = shufflers4(l)
  t  = shufflers5(l2)
  t2 = shufflers6(t)
  write(t2)  
end

#--------------
def shufflers1() #preparation
  a1 = read("shufflers.txt")
  #a1 = read("sample.txt")
  #a1 = read("answer.txt")
  a2 = []

  for i in 0...a1.length
    a2[a2.length] = div_ss(a1[i]," ")
  end

  b = []
  c = []

  for i in 0...a2.length
    f = 0
    for j in 0...a2[i].length
      if a2[i][j] == "="
        f = j
        break
      end
    end
    b[b.length] = a2[i][0..f-1]
    c[c.length] = a2[i][f+1..a2[i].length-1]
  end

  return [b,c]
=begin
  for i in 0...a.length
    k = serch_ss(a[i],"=")
    b1[b1.length] = a[i][0..k-2]
    c1[c1.length] = a[i][k+2..a.length-1]
  end
  for i in 0...a.length
    b2[b2.length] = div_ss(b1[i]," ")
    c2[c2.length] = div_ss(c1[i]," ")
  end
=end

  #return [a,b2,c1]
end

def read(st)
  a = []
  f = open(st)
  f.each_line {|line| a[a.length] = line.chomp}
  f.close
  return a
end

def serch_ss(st,ss) #serch first ss from st
  for i in 0...st.length
    if st[i..i] == ss
      return i
      break
    end
  end
  return -1
end

def div_ss(st,ss) #cut off st at ss
  s = st
  a = []
  k = serch_ss(st,ss)
  while (k != -1) && (k < s.length) && (k > -1)
    a[a.length] = s[0..k-1]
    s = s[k+1..s.length-1]
    k = serch_ss(s,ss)
  end
  
  if s != ""
    a[a.length] = s
  end
  
  return a
end

#-------------------
def shufflers2(a) #a: [[ids[]],[names[]]]
  b = list(a[0])
  c = list(a[1])

  return [b,c]
end

def list(a) #a: [[x,y..],[w,z..]..]
  l = []
  for i in 0...a.length
    for j in 0...a[i].length
      if nowhere(l,a[i][j])
          l[l.length] = a[i][j]
      end
    end
  end
  return l #l: [x,y,w,z..]
end

def nowhere(a,s)
  f = true
  for i in 0...a.length
    if a[i] == s
      f = false
      break
    end
  end
  return f
end
#-------------------
#a:shufflers1, names:shufflers2[1]
def shufflers3(a,names)
  ids = Array.new(names.length)
  for i in 0...names.length
    ids[i] = ids(a,names[i])
  end
  
  return [ids,names]
end

def ids(a,st)
  ids = []
  for i in 0...a[1].length
    if !nowhere(a[1][i],st) #if there are st in a[1][i]
      ids[ids.length] = a[0][i]
    end
  end

  return allapears(ids)
end

def allapears(a)
  l =a[0]
  for i in 1...a.length
    l = l & a[i]
  end
  return l
end
#-------------------
def shufflers4(a) #a: [[ids[]],[names]]
  l = slim(a)
  while a != l
    a = l
    l = slim(l)
  end
  return l
end

def slim(a)
  l = a
  for i in 0...a[1].length
    if a[0][i].length == 1
      d = a[0][i][0]

      for j in 0...a[0].length
        k = whereis(a[0][j],d)
        if k>=0 && j!=i
          l[0][j].delete_at(k)
        end
      end
    end
  end
  
  return l
end

def whereis(a,s)
  k=-1
  for i in 0...a.length
    if a[i] == s
      k=i
      break
    end
  end
  return k
end
#--------------------
#convert to txt
#a:l2, [[ids[]],[names]]
def shufflers5(a)
  b = list([a[0]])
  c = Array.new(b.length)
  for i in 0...b.length
    temp = []
    for j in 0...a[0].length
      if a[0][j] == b[i]
        temp[temp.length] = a[1][j]
      end
    end
    c[i] = temp
  end
  return [b,c] #[[id[]],[names[]]]
end
#---------------------
#[[ids[]],[names[]]] to [id&names]
def shufflers6(a)
  b = Array.new(a[0].length)
  for i in 0...b.length
    b[i] = combine(a[0][i],a[1][i])
  end
  return b.sort
end

def combine(a,b) #a,b: []
  s = ""
  for i in 0...a.length
    s += a[i] + " "
  end
  s += "="
  for i in 0...b.length
    s += " " + b[i]
  end
  return s
end
#-------------------
def write(a)
  st = ""
  for i in 0...a.length
    st += a[i] + "\n"
  end
  open("answer.txt","w"){|f| f.write st}
end

#--------------------
def test(st)
  ss = st
  ss += "a"
  return ss
end

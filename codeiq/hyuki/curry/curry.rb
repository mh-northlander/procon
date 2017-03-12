#b=blendlist()
#s=spicelist(b)
#c : spice set
#check(b,s,c) : return point(minus)
#myspicelist(s,c)
#hoge1(b,s) : return c, &puts point

#blendlist() & spicelist(b)
def read() #read each lines
  a=[]
  f=open("blendlist.txt")
  f.each_line {|line|
    a[a.length] = line.chomp} #add line to a's last,cutting enter
  f.close
  return a
end

def blendlist()
  a = read()
  b = Array.new(a.length)
  for i in 0...b.length
    b[i] = devide(a,i)
  end
  return b
end

def devide(a,i) #devide a[i] at first "space"
  k = whereisspace(a[i])
  return [a[i][0..k-1],a[i][k+1..a.length-1]]  
end

def whereisspace(s) #first space
  for i in 0...s.length
    if s[i] == " "
      return i
      break
    end
  end
  return -1
end

def spicelist(a) #a is blendlist
  s=[]
  for i in 0...a.length
    for j in 0...a[i].length
      f = true
      for k in 0..s.length
        if s[k]==a[i][j]
          f = false
          break
        end
      end
      if f
        s[s.length] = a[i][j]
      end
    end
  end
  return s
end

#----------------

def hme(a,b) #a:spiceL, b:blendL
  c = Array.new(a.length,0)
  for i in 0...a.length
    for j in 0...b.length
      for k in 0...b[j].length
        if a[i]==b[j][k]
          c[i]+=1
        end
      end
    end
  end
  return c
end

#----------------checker
def minnum #at least answer must be better than this
  return 22
end

def allgrps(b,s,k) #all groups taking k from s:spiceL
  nck = combi(s.length,k)

  c = Array.new(s.length,0)
  for i in 0...k
    c[i]=1
  end

  result = []

  hm1=0 #how many 1 at last
  u=0
  t=0

  while true
    hm1 = 0
    for i in 1..c.length
      u = c.length-i #reverce
      if c[u] == 1
        hm1 += 1
        c[u] = 0
      else
        break #1
      end
    end
    #1 is to here
    if hm1 == k #condition to end
      break
    else
      for i in 1..c.length
        t = c.length-i #reverce 
        if c[t] == 1
          c[t] = 0
          for j in (t+1)..(t+1+hm1)
            c[j] = 1
          end
          break #2
        end
      end
      #2 is to here, and do your work here
      #puts c.to_s
      che = check(b,s,c)
      if che != nil
        result[result.length] = che
      end
    end
    puts k.to_s + "-" + nck.to_s
    nck -= 1
  end
  return result
end

def check(b,s,c) #blendL, spiceL, spice set. 
  point = 0 #(minus)
  sp0=""
  sp1=""
  spf0=0
  spf1=0
  for i in 0...b.length
    sp0 = b[i][0]
    sp1 = b[i][1]
    for j in 0...s.length
      if s[j] == sp0
        spf0 = c[j]
      end
      if s[j] == sp1
        spf1 = c[j]
      end
    end
    if spf0 != spf1
      point += 1
    end
#    if point > minnum()
#      break
#    end
  end
  return point
#  if point <= minnum()
#    return myspicelist(s,c)
#  end
end

def myspicelist(s,c)
  msl = []
  for i in 0...c.length
    if c[i] == 1
      msl[msl.length] = s[i]
    end
  end
  return msl
end

#---------------

def curry(b,s)
  result = []
  for i in 1..(s.length/2)
    alg = allgrps(b,s,i)
    if alg != nil
      result[result.length] = alg
    end
  end
  return result
end

#--------------
def combi(n,k)
  c = make2d(n+1,n+1)
  for i in 0..n
    c[i ][0] = 1
    for j in 1...i
      c[i][j] = c[i-1][j-1] + c[i-1][j]
    end
    c[i][i] = 1
  end
  return c[n][k]
end

def make2d(m,n)
  a=Array.new(m)
  for i in 0...a.length
    a[i]=Array.new(n,0.0)
  end
  return a
end

#-----------------
include Math

def ranss(s)
  rs = Array.new(s.length)
  for i in 0...rs.length
    rs[i] = rand(2)
  end
  return rs
end

def rans(s)
  rs = Array.new(s.length)
  for i in 0...rs.length
    rs[i] = i
  end
  return  rs.sort_by{rand}
end

def changek(c,k)
  if c[k]==0
    c[k]=1
  else
    c[k]=0
  end
  return c
end

#-----------------

def hoge1(b,s)
  c = ranss(s)

  #result
  p = check(b,s,c)

  while true
    rs = rans(s)
    f = false
    for i in 0...rs.length
      cc = changek(c,rs[i])
      if p > check(b,s,cc)
        c = cc
        p = check(b,s,cc)
        f = true
      end
    end

    if f == false
      break
    end

    puts "rep"
  end #of while

  puts p
  return c
end
#---------------

def hoge2(b,s,pc)
  c = changek(pc,rand(pc.length))

  #result
  p = check(b,s,c)

  while true
    rs = rans(s)
    f = false
    for i in 0...rs.length
      cc = changek(c,rs[i])
      if p > check(b,s,cc)
        c = cc
        p = check(b,s,cc)
        f = true
      end
    end

    if f == false
      break
    end

    puts "rep"
  end #of while

  puts p
  return c
end
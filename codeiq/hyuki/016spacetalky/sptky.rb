#write(sptky(read()))

#read()
#write(a)
#alp()
#a2n(s) :s is Nth alph~
#alpkth(s,k) :return string which append s k times
#sptky(a) 

#can't read "end", "rescue", "return"
def read()
  a=[]
  f=open("words.txt")
  f.each_line {|line|
    a[a.length]=line.chomp}
  f.close
  return a
end
def write(a)
  st=""
  for i in 0...a.length
    st += a[i].to_s + "\n"
  end
  open("ans.txt","w") {|f| f.write st}
end

def alp()
  return ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
end
def a2n(s)
  al=alp()
  for i in 1..al.length
    if al[i-1] == s
      return i
    end
  end
  return 0
end
def alpkth(s,k)
  st=""
  for i in 1..k
    st+=s
  end
  return st
end

def sptky(a)
  b=[]
  for i in 0...a.length
    if a[i].length % 2 == 1
      b[i] = "X"
    else
      b[i]=""
      for j in 0...a[i].length/2
        b[i]+=alpkth(a[i][2*j],a2n(a[i][2*j+1]))
      end
    end
  end
  #return b #: 
  c=[]
  for i in 0...b.length
    c[i] = b[i] + ":" + a[i]
  end
  return c
end


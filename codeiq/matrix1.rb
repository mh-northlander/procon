

def vwxyz()
  return [9,3,9,2,4,5]
end

def del0(a)
  al = a.length
  t=0
  for i in 0...al
    if a[i]==0
      t += 1
    end
  end
  b = Array.new(al - t)
  j=0
  for i in 0...al
    if a[i] != 0
      b[j] = a[i]
      j += 1
    end
  end
  return b
end

def dels(a,s)
  b=[]
  for i in 0...a.length
    if i!=s
      b << a[i]
    end
  end
  return b
end

def pick(a,s,t)
  b = Array.new(t-s+1)
  for i in s..t
    b[i] = a[i]
  end
  return b
end

def hoge1(a,n,st)
  al = a.length
  if al == 2
    puts [st,n]
  else
    for i in 1..(al-2)
      s += i.to_s
      n *= a[i-1]*a[i]*a[i+1]
    end
  end
end

def hoge2(a)
  al = a.length
  if al==2
    return 1
  else
    b=Array.new(al-2)
    for i in 0...b.length
      b[i] = a[i]*a[i+1]*a[i+2]*hoge2(dels(a,i+1))
    end
    return b.min
  end
end

def minid(a)
  m = a.min
  for i in 0...a.length
    if a[i]==m
      return i
    end
  end
end

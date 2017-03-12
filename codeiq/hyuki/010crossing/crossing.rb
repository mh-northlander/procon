#1 simply count crosses
#2 serch and change i
#3 bubble
#4 
#


def crossing1() #O=N**2
  p Time.now
  #a = read("crossing.txt")
  a = read("smpl.txt")
  cross = 0
  for i in 0...a.length
    for j in 0...i
      if a[i] < a[j]
        cross+=1
      end
    end
  end
  p Time.now
  return cross
end

def read(s)
  f=open(s)
  a=[]
  f.each_line{|line| a[a.length]=line.to_i}
  f.close

  return a
end

#------------------

def crossing2()
  p Time.now
  #a=read("crossing.txt")
  a=read("smpl.txt")
  c=0

  for i in 0...a.length
    k=0
    if a[i]!=i+1
      j=i+1
      while (a[j] != i+1) && j<a.length
        if a[j]<a[i]
          k+=1
        end
        j+=1
      end
      a = change(a,i,j)
      c += 2*k +1
    end
  end

  p Time.now
  return c
end

def change(a,i,j)
  temp = a[i]
  a[i] = a[j]
  a[j] = temp
  return a
end

#-----------

def crossing3()
  p Time.now
  #a=read("crossing.txt")
  a=read("smpl.txt")
  c=0

  f=0
  while f==0
    f=1
    for i in 1...a.length
      if a[i-1]>=a[i]
        a = change(a,i-1,i)
      end
    end
  end

  p Time.now
  return c
end

#-----------

def crossing4()
  p Time.now
  #a=read("crossing.txt")
  a=read("smpl.txt")
  c=0

  i=0
  while i<a.length
    if a[i]==i+1
      i+=1
    else
      k=0
      for j in i+1...a[i]-1 #i should in a[i-1]
        k+=between(a[j],a[i],a[a[i]-1])
      end
      
      if a[i]>a[a[i]-1]
        c += k*2 +1
      else
        c -= k*2 +1
      end
      a=change(a,i,a[i]-1)
    end
  end

  p Time.now
  return c
end

def between(a,i,j)
  if (a<i && a>j) || (a>i && a<j)
    return 1
  else
    return 0
  end
end

#-----------

def crossing5()
  p Time.now
  #a=read("crossing.txt")
  a=read("smpl.txt")
  c=0
  
  for i in 0...a.length
    if a[i] != i+1
      c+= cutoff(i+1-a[i])
    else
      k=0
      for j in 0..i
        if a[j] > a[i]
          k+=1
        end
      end
      c+= k
    end
  end

  p Time.now
  return c
end

def cutoff(n)
  if n<0
    return 0
  else
    return n
  end
end

#-----------

def crossing6()
  p Time.now
  #a=read("crossing.txt")
  a=read("smpl.txt")
  #a=read("sample.txt")
  c=0

  c = cross(a,0,a.length-1)

  p Time.now
  return c
end

def cross(a,k,l)
  if l-k==0
    return 0
  elsif l-k==1
    if a[k]>a[l]
      return 1
    else
      return 0
    end
  elsif l-k>=2
    n=0
    m=0
    med = (k+l)/2
    for i in k...med
      if a[med]<a[i]
        n+=1
      end
    end
    for i in med+1..l
      if a[med]>a[i]
        m+=1
      end
    end
    return 2*n*m +n+m +cross(a,k,med-1)+cross(a,med+1,l)
  else return 0
  end
end

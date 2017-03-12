
def g(n)
  if n==1
    return [[1]]
  else
    a=g(n-2)
    b=5+4*(n+1)/2*((n+1)/2-2)
    a << Array.new(n-1)
    a.unshift(Array.new(n-1))
    for i in 1...n
      a[0][i-1]=n*(n-1)+i+1
      a[n-1][i-1]=b-i+1
      a[i] << (n-2)**2+i
      a[n-i-1].unshift(b+i)
    end
    return a
  end
end
def c(n)
  a=g(n)
  l=((n**2).to_s).length
  for i in 0...n
    for j in 0...n
      a[i][j]=a[i][j].to_s
      d=l-a[i][j].length
      while d>0
        a[i][j]=" "+a[i][j]
        d-=1
      end
    end
  end
  return a
end
def w1(n)
  w=c(n)
  s=""
  for i in 0...n
    for j in 0...n
      s+=w[i][j]+" "
    end
    s.strip
    s+="\n"
  end
  open("grgru.txt","w"){|f| f.write s}
end

def g2(k)
  if k==1
    return [[1]]
  else
    a=g2(k-2)
    
    return a
  end
end

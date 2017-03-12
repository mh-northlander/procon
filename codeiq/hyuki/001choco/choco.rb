include Math

def n()
  return 280671392065546467397265294532969672241810318954163887187279320454220348884327
end

def nn()
  return 481362815814826159
end

def np()
  return [162425297,215940091,358456949,369941863,369941863,479871607,706170617,481362815814826159]
end

def test(n)
  div = 100000001
  while (n%div!=0)&&(n%(div+2)!=0)&&(n%(div+6)!=0)&&(n%(div+8)!=0)&&(n%(div+12)!=0)&&(n%(div+18)!=0)&&(n%(div+20)!=0)&&(n%(div+26)!=0) &&(n>div)
    div += 30
    puts div
  end
  return div
end

def test2(n)
  div = 100000001
  sn = sqrt(n)+10
  while (n%div!=0)&&(n%(div+4)!=0) &&(sn>div)
    div += 6
    puts div
  end
  return div
end

def rolow(n)
  y = x = rand(n) #x1
  c = 11
  x = f(x,c,n) #x2
  d = 1

  ubound = sqrt(n).to_i + 2
  nx2p = 2
  i=1
  while (d==1) && (i<ubound)
    d = abs( gcd(abs(x-y),n) )
    
    if i == nx2p
      y = x
      nx2p *= 2
    end
    
    i+=1
    puts i 
    x = f(x,c,n)
  end
  return d
end

def f(x,c,n)
  return (x**2+c)%n
end
def gcd(a,b)
  while (a%=b)!=0
    a,b = b,a
  end
  return b
end
def abs(a)
  if a<0
    return -a
  else
    return a
  end
end
def div_while_divisible(n,a)
  while n%a == 0
    n /= a
    puts a
  end
  return n
end

def eratosthenes(n)
  p = Array.new(n,0)
  for i in 0...p.length # [2,3,4,5,...,n]
    p[i] = i+2
  end
  i = 0
  j = 0
  while i < p.length 
    #puts p[i]
    j = i + p[i]
    while j < p.length
      #puts p[j]
      p[j] = 0
      j += p[i]
    end
    i += 1
    while (i<p.length) && (p[i]==0)
      i += 1
    end
    if i>=p.length
      break
    end
  end
  
  ps = []
  for i in 0...p.length
    if p[i] != 0
      ps[ps.length] = p[i]
    end
  end
  return ps
end


def bunkai(n)
  ps = eratosthenes(sqrt(n).to_i + 2)
  pc = Array.new(ps.length,0)
  #for i in 0...p.length
  #  p[i] = Array.new(2,0)
  #end
  #for i in 0...ps.length
  #  p[i][0] = ps[i]
  #end
  nn = n
  for i in 0...ps.length
    while nn % ps[i] == 0
      pc[i] += 1
      nn /= ps[i]
    end
  end
  #puts pc
  p = []
  for i in 0...pc.length
    if pc[i] != 0
      p[p.length] = [ps[i],pc[i]]
    end
  end

  if p != []
    return p
  else
    return 0
  end
end

def searchp(n)
  ps = eratosthenes(10000000)
  puts "endera"
  
end

def choco()
  ps = [1.62425297, 2.15940091, 3.58456949, 3.69941863, 3.69941863, 4.79871607, 7.06170617, 48.1362815814826159]
  pc = []
  for i in 0...ps.length
    pc[pc.length] = [ps[i],0]
  end
  set = [[1,1,6],[1,2,5],[1,3,4],[2,2,4],[2,3,3]]
  list = []
  for i in 0...set.length
    for j in 0...set[i].length #(3)
      for k in 0..set[i][j]
        
      end
    end
  end
  
end

def s(a,b,c)
  return (a*b + b*c + c*a)*2
end


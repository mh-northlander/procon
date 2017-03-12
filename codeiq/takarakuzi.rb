
def howmuch()
  return 200001 + rand(100000)
end

def test()
  a = Array.new(3)
  a[0]=1
  a[1]=2
  a[2]=3
  return a.sort_by{rand}
end

def buied(n)
  nums=Array.new(40)
  for i in 0...nums.length
    nums[i]=i+1
  end
  
  b = Array.new(n)
  for i in 0...b.length
    b[i]=Array.new(5,0)
    num = nums.sort_by{rand}
    for j in 0..4
      b[i][j] = num[j]
    end
  end
  return b
end

def atari()
  return buied(1)
end

def isatari(b,atari)
  flg=0
  for i in 0...b.length
    for j in 0...atari.length
      if b[i] == atari[j]
        flg += 1
      end
    end
  end

  case flg
  when 5
    return 1
  when 4
    return 2
  when 3
    return 3
  else 
    return 0
  end
end


def takara(my)
  n = howmuch
  b = buied(n)
  a = atari()
  puts ((n+1)*500).to_s + "were buied"
  puts "master gets " + ((n+1)*500*0.4).to_s
  puts "atari is " +a[0].to_s

  b[b.length] = my
  c = check(b,a)
  jun = (n+1)*500*0.6
  puts "1:" + n[1].to_s + "person, " + (jun*0.1/2*n[1]).to_s + "yen"
  puts "2:" + n[2].to_s + "person, " + (jun*0.1/3*n[2]).to_s + "yen"
  puts "3:" + n[3].to_s + "person, " + (jun*0.1/6*n[3]).to_s + "yen"
  
  puts "you're " + (isatari(my,a)).to_s
end

def check(b,a)
  n = [0,0,0,0]  
  for i in 0...b.length
    n[isatari(b[i],a)] += 1
  end
  return n
end

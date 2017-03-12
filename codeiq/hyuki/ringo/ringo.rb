#a= read()
#count(st) count how many times each alp appears
#s= encode(st,code)
#s= decode(st,code)
#writecode(code)

def read()
  f=open("typical.txt")
  a = f.read
  f.close

  return a
end

def alp()
  return ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
end

def code0() #24971 is this min?
  return ["gg","bbbr","rgbr","rbb","rr","gbbg","rgbb","rgr","br","bbbbr","gbbr","gbr","rgbg","rgg","bg","gbbb","bbbbg","rbg","rbr","gr","gbg","bbbg","bbr","bbbbbr","bbg","bbbbbg"]
end
def code1()
  
end

def count(st)
  alp = alp()
  count = Array.new(alp.length,0)

  #
  #st.each_byte {|c|
  #  for i in 0...alp.length
  #    if c == alp[i]
  #      count[i] += 1
  #      break
  #    end
  #  end
  #}

  for i in 0...st.length
    for j in 0...alp.length
      if st[i..i] == alp[j]
        count[j]+=1
        break
      end
    end
  end

  return count
end

def encode(st,code)
  alp = alp()
  s=""
  for i in 0...st.length
    for j in 0...alp.length
      if st[i..i]==alp[j]
        s += code[j]
        break
      end
      #s += " " #if st[i] is not A~Z
    end
  end
  return s
end

def decode(st,code)
  i=0
  j=0
  s=""
  alp = alp()
  while j < st.length
    for k in 0...code.length
      if st[i..j] == code[k]
        s += alp[k] 
        i = j = j+1
        break
      end
    end
    if j >= st.length-1 && i!=j #last time
      puts "failure decoding" 
    end
    j+=1
  end
  return s
end

def writecode(code)
  st = ""
  alp=alp()
  for i in 0...alp.length
    st+= alp[i] + ":" + code[i] + "\n"
  end

  open("answer.txt","w"){|f| f.write st}
end

def test(st)
  st.each_byte{|c|
    puts c
  }
end

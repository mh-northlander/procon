
def toggle(k)
  toggles = []
  toggles[toggles.length] = ""
  for i in 0...k
    toggles[0] += "0"
  end
  
  for i in 1...2**k
    if i%2==1
      toggles[toggles.length] = reverse(toggles[toggles.length-1])
    else
      for j in 0...k
        temp = reverse_notk(toggles[toggles.length-1],j)
        if isnew(temp,toggles)
          toggles[toggles.length] = temp
          break
        end
      end
    end
  end

  return toggles
end

#difference of a[k-1]->a[k]
def money(a,k)
  a1 = a[k-1]
  a2 = a[k]
  c=0
  for i in 0...a1.length
    if a1[i]!=a2[i]
      c += 1
    end
  end
  return c
end

def allmoney(a) # (2k-1) * 2**(k-1)
  sum=0
  for i in 1...a.length
    sum += money(a,i)
  end
  return sum
end
#--------------
def reverse(s)
  ss=""
  for i in 0...s.length
    if s[i,1] == "1"
      ss += "0"
    else
      ss += "1"
    end
  end
  return ss
end

def reverse_k(s,k)
  #ss = s :NG, pass copy
  ss = ""
  for i in 0...s.length
    ss += s[i,1]
  end

  if ss[k,1] == "1"
    ss[k,1] = "0"
  else
    ss[k,1] = "1"
  end
  return ss
end

def reverse_notk(s,k)
  return reverse(reverse_k(s,k))
end

#-----------------------

def isalldiff(a)
  f = true
  for i in 0...a.length
    for k in (i+1)...a.length
      if a[i] == a[k]
        f = false
      end
      break
    end
  end

  return f
end

def isnew(s,a)
  f = true
  for i in 0...a.length
    if a[i]==s
      f =false
    end
  end
  return f
end

#----------------------
def writeans(a)
  st = ""
  for i in 0...a.length
    st += a[i] + "\n"
  end
  
  open("answer.txt","w"){|f| f.write st}
end

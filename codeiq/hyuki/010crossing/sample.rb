
def make_sample(k)
  st=""
  a=(1..k).sort_by{rand}
  for i in 0...a.length
    st += a[i].to_s + "\n"
  end

  open("smpl.txt","w"){|f| f.write st}
end

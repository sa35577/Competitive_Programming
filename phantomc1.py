print" ".join(`z`+" *"[[y.__setitem__(x,0)for x in y[z*z::z]]>0<y[z-2]|y[z+2]]for y in[range(input())]for z in y if z>1)

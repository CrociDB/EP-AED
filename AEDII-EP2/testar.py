import random
import os

num_testes = 500
num_ok = 0

for i in xrange(num_testes):
   print "Teste {0}".format(i+1)
   
   m = random.randint(3, 10)
   k = random.randint(3, 10)
   n = random.randint(30, 200)
   
   print " ~> M: {0}, K: {1}, N: {2}".format(m,k,n)
   
   num = [random.randint(1, 50000) for j in xrange(n)]
   
   text_file = "{0} {1} {2}\n".format(m, k, n)
   for j in num: text_file += str(j) + " "
   
   num.sort();
   
   text_file_result = ""
   for j in num: text_file_result += str(j) + " "
   
   
   f = open('test_in', 'w')
   f.write(text_file)
   f.close()
   os.system("./ep test_in test_out >/dev/null 2>/dev/null")
   
   f = open('test_out', 'r')
   f = f.read()
   
   if f == text_file_result: 
      num_ok += 1
      print " ~> OK"
   else: print " ~> FUUUUUU"
   
print ""
print ""
print " === RESULTADOS ==="
print "  ~> Numero de testes: {0}".format(num_testes)
print "  ~> Numero de acertos: {0}".format(num_ok)
print "  ~> Porcentagem de acertos: {0}%".format(num_ok * 100 / num_testes)

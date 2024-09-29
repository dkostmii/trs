make clean && make

run() {
  n_proccesses=$1

  echo "Запуск для кількості процесів: N=$n_proccesses"
  for i in {1..3}; do
    echo "Запуск $i"
    mpiexec -n $n_proccesses ./main
  done
}

run 7
run 23

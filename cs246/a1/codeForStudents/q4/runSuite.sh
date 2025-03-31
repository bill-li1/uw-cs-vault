#!/bin/bash

incorrect_param () {
  echo "Incorrect number of arguments" >&2
}

cannot_read_one() {
  echo ${1} is not readable >&2
}

cannot_read_two() {
  echo File ${1} does not exist or is not readable >&2
}

cannot_execute() {
  echo ${1} is not executable >&2
}

cannot_write() {
  echo ${1} is not writable
}

if [ ${#} -ne 2 ]; then
  incorrect_param
  exit 1
fi

if [ ! -r ${1} ]; then
  cannot_read_two ${1}
  exit 1
fi

if [ ! -x ${2} ]; then
  cannot_execute ${2}
  exit 1
fi

flag=0

for test_file in $(cat ${1}); do
  skipFlag=0
  OUT=$(mktemp /tmp/output.XXXXXXXXXX)

  if [ -f ${test_file}.args -a ! -r ${test_file}.args ]; then
    cannot_read_one ${test_file}.args
    errorFlag=1
    skipFlag=1
  fi

  if [ ! -f ${test_file}.out -o ! -r ${test_file}.out ]; then
    cannot_read_two ${test_file}.args
    exit 1
  fi 

  if [ $skipFlag -eq 0 ]; then
    if [ ! -f ${test_file}.args ]; then
      ${2} > OUT
    else
      ${2} $(cat ${test_file}.args) > OUT
    fi
    cmp --silent OUT ${test_file}.out
    if [ ${?} -eq 1 ]; then
      echo "Test failed: ${test_file}"
      if [ ! -f ${test_file}.args ]; then
        echo "Args:"
        echo "Expected:"
        cat ${test_file}.out
        echo "Actual:"
        cat OUT
      else
        echo "Args:"
        cat ${test_file}.args
        echo "Expected:"
        cat ${test_file}.out
        echo "Actual:"
        cat OUT
      fi
    fi
  fi
  if [ -f OUT ]; then
    rm OUT
  fi
done

exit $flag


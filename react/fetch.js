async function f() {
  try {
    let response = await fetch('http://no-such-url');
  } catch (err) {
    alert(err);
  }
  return 111;
}


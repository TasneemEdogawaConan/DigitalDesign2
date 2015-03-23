  input md[0];
  input md[1];
  input md[2];
  input md[3];
  input mr[0];
  input mr[1];
  input mr[2];
  input mr[3];
  output x[0];
  output x[1];
  output x[2];
  output x[3];
  output z[0];
  output z[1];
  output z[2];
  output z[3];

  INVX1 _2_ (
    .A(md[1]),
    .Y(_0_)
  );
  NOR2X1 _3_ (
    .A(x[0]),
    .B(_0_),
    .Y(x[1])
  );
  XOR2X1 _4_ (
    .A(x[0]),
    .B(md[1]),
    .Y(z[1])
  );
  AND2X2 _5_ (
    .A(_0_),
    .B(md[2]),
    .Y(x[2])
  );
  XOR2X1 _6_ (
    .A(md[1]),
    .B(md[2]),
    .Y(z[2])
  );
  INVX1 _7_ (
    .A(md[3]),
    .Y(_1_)
  );
  NOR2X1 _8_ (
    .A(md[2]),
    .B(_1_),
    .Y(x[3])
  );
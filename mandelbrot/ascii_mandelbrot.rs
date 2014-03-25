// includes

extern crate extra;



// constants

static THRESHOLD:  f64 = 2.;
static ITERATIONS: int = 50;



// types

struct Complex {
    r: f64,
    i: f64
}



// impls

impl Complex {
    fn abs(&self) -> f64 {
        (self.r * self.r + self.i * self.i).sqrt()
    }
}



// traits

impl Add<Complex, Complex> for Complex {
    fn add(&self, other: &Complex) -> Complex {
        Complex {r: self.r + other.r, i: self.i + other.i}
    }
}

impl Sub<Complex, Complex> for Complex {
    fn sub(&self, other: &Complex) -> Complex {
        Complex {r: self.r - other.r, i: self.i - other.i}
    }
}

impl Mul<Complex, Complex> for Complex {
    fn mul(&self, other: &Complex) -> Complex {
        Complex {r: self.r * other.r - self.i * other.i,
                 i: self.r * other.i + self.i * other.r}
    }
}



// code

fn mandelbrot(p: Complex) -> f64 {
    let mut z = Complex { r:0., i:0. };

    for _ in range(0, ITERATIONS) {
        z = p + z * z;
    }

    return z.abs();
}



// main

fn main() {
    for sy in range(0, 41) {
        for sx in range(0, 80) {
            let p = Complex { r: -2. + sx as f64 * 0.0315,
                              i:  1. - sy as f64 * 0.0500 };
            let c = if mandelbrot(p) < THRESHOLD { "#" } else { " " };
            print!("{}", c);
        }
        println!("");
    }
}

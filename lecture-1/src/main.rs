
/*
Faça uma função que aloque um vetor de n posições. O tamanho do vetor é passado por parâmetro. Após
criar o vetor, a função deve preencher este vetor (nos índices pares com 0, nos índices ímpares com o valor
quadrado do índice), imprimindo os mesmos na tela. A função deve retornar 1 se conseguiu alocar o vetor, e
0 em caso contrário.
*/
use std::mem::{size_of, MaybeUninit};

fn main() {
    let mut input = String::new();

    print!("Digite o número de posições: ");

    std::io::stdin().read_line(&mut input).unwrap();

    let size: usize = match input.trim().parse() {
        Ok(value) => value,
        Err(e) => {
            eprintln!("Não foi é possível fazer parse para usize: {}", e);

            std::process::exit(0)
        }
    };

    match alloc_vector(size) {
        Some(vec) => {
            std::process::exit(1);
        },
        None => {
            eprintln!("Não foi possível alocar o vetor com: {} posições", size);
            std::process::exit(0)
        }
    }

}


fn alloc_vector(size: usize) -> Option<Vec<i8>> {
    let slice = unsafe { libc::malloc(size_of::<i8>() * size) };

    if slice.is_null() {
        return None
    }

    let vec: Vec<i8> = unsafe { Vec::from_raw_parts(slice, size, size) }
        .into_iter()
        .enumerate()
        .map(|i| i.0)
        .map(|i|
            if i&1 == 0 {
                0
            }
            else {
                i*i
            }
        ).enumerate()
        .inspect(|i| println!("Index: {}, value: {}", i.0, i.1))
        .map(|i| i.1 as i8)
        .collect();

    Some(vec)
}
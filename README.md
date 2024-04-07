Certainly! Here's the refactored README for the "Stupid_CMD" library:

---

# Stupid_CMD Documentation

## Overview

Stupid_CMD é uma biblioteca simples em C que fornece funcionalidades básicas de linha de comando, incluindo um histórico de comandos, comandos personalizados e a capacidade de executar comandos externos. Esta documentação descreve o uso básico, os comandos permitidos e as limitações potenciais.

## Uso

1. **Incluindo a Biblioteca:**

    ```c
    #include "stupid_cmd.h"
    ```

2. **Inicializando o Histórico de Comandos:**

    ```c
    Node* history = NULL; // Declare um ponteiro de histórico
    ```

3. **Adicionando Comandos ao Histórico:**

    ```c
    history = add_history(history, "seu_comando_aqui");
    ```

4. **Mostrando o Histórico de Comandos:**

    ```c
    show_history(history);
    ```

5. **Executando Comandos:**

    - **Comandos Internos:**
        - `exit`: Sai da interface de linha de comando.
        - `history`: Exibe o histórico de comandos.
        - `ls`: Lista os arquivos no diretório atual.
        - `cd <diretório>`: Altera o diretório atual.
        - `pwd`: Imprime o diretório de trabalho atual.
        - `clear`: Limpa a tela do console.
        - `mkdir <diretório>`: Cria um novo diretório.
        - `touch <arquivo>`: Cria um novo arquivo vazio.

    - **Comandos Externos:**
        ```c
        execute_external_command("seu_comando_externo_aqui");
        ```

6. **Liberando o Histórico de Comandos:**

    ```c
    free_history(history);
    ```

## Limitações

- A biblioteca é projetada para interações básicas de linha de comando e pode não lidar com cenários complexos.
- A execução de comandos externos depende das capacidades do sistema subjacente e pode ter limitações.

## Notas

- Personalize o loop principal no exemplo para se adequar às necessidades do seu aplicativo.
- Consulte as funções da biblioteca para obter mais detalhes sobre cada comando.

Sinta-se à vontade para integrar o Stupid_CMD em seu projeto e adaptá-lo conforme necessário!

---

1. **Redirecionamento de entrada/saída:** Permitir redirecionamento de entrada e saída, como redirecionamento de arquivo (`>`, `<`) e pipes (`|`), para possibilitar a execução de comandos mais avançados e encadeados.

2. **Gestão de variáveis de ambiente:** Adicionar suporte para definir, acessar e modificar variáveis de ambiente, como `PATH`, `HOME`, `USER`, etc., para melhorar a personalização e a interoperabilidade do shell.

3. **Completar comando automaticamente:** Implementar uma funcionalidade de autocompletar comando ao pressionar a tecla TAB, para ajudar os usuários a digitar comandos mais rapidamente e evitar erros de digitação.

4. **Histórico avançado:** Melhorar o histórico de comandos com recursos como pesquisa incremental, filtros por data, hora ou usuário, e a capacidade de editar comandos antes de executá-los.

5. **Personalização do prompt:** Permitir que os usuários personalizem o prompt de comando com informações como nome de usuário, diretório atual, hora, etc., para tornar a interface mais informativa e esteticamente agradável.


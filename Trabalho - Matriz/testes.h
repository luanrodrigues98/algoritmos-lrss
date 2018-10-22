//Testes para verificar a funcionalidade de métodos e overloads de operadores

TEST(MATRIX, get_linhas){
     Matrix mat(2,2);
     ASSERT_EQ(2, mat.getLinhas());
}

TEST(MATRIX, get_colunas){
     Matrix mat(4,5);
     ASSERT_EQ(5, mat.getColunas());
}

TEST(MATRIX, operator_assigment){
     Matrix mat(2,2);
     Matrix mat2(2,2);

     for(int i = 0; i < 2; i++){
 	for(int j = 0; j < 2; j++){
	    mat[i][j] = 1;
            mat2[i][j] = 2;
        }
     }
     mat = mat2;
     ASSERT_EQ(2, mat[0][1]);
}

TEST(MATRIX, operator_brackets){
     Matrix mat (2,2);
     mat[0][1] = 54;
     ASSERT_EQ(54, mat[0][1]);
}








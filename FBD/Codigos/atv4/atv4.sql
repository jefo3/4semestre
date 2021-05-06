CREATE TABLE if not exists Curso(
	numCurso int PRIMARY KEY NOT NULL,
	nome char(100) NOT NULL,
	totalCreditos int NOT NULL
	
);

CREATE TABLE if not exists Disciplina(
	numDisc int PRIMARY KEY NOT NULL,
	nome char(100) NOT NULL,
	qntCreditos int NOT NULL
);

CREATE TABLE if not exists RefDisciplinaEmCurso(
 	disciplina int NOT NULL,
	curso int NOT NULL,
	
	CONSTRAINT disciplina_fk FOREIGN KEY(disciplina) REFERENCES Disciplina(numDisc),
	CONSTRAINT curso_fk FOREIGN KEY(curso) REFERENCES Curso(numCurso)
	
);

CREATE TABLE if not exists Aluno(
	numAluno int PRIMARY KEY NOT NULL,
	nome char(100) NOT NULL,
	endereco text NOT NULL,
	cidade char(100) NOT NULL,
	telefone char(20) NOT NULL,
	
	curso int NOT NULL,
	
	CONSTRAINT curso_fk FOREIGN KEY(curso) REFERENCES Curso(numCurso)
);

CREATE TABLE if not exists Professor(
	numProf int PRIMARY KEY NOT NULL,
	nome char(100) NOT NULL,
	areaPesquisa char(100) NOT NULL
);

CREATE TABLE if not exists Aula(
	semestre text NOT NULL,
	nota decimal(10,2) NOT NULL,
	
	disciplina int NOT NULL,
	professor int NOT NULL,
	aluno int,
	
	CONSTRAINT disciplina_fk FOREIGN KEY(disciplina) REFERENCES Disciplina(numDisc),
	CONSTRAINT professor_fk FOREIGN KEY(professor) REFERENCES Professor(numProf),
	CONSTRAINT aluno_fk FOREIGN KEY(aluno) REFERENCES Aluno(numAluno)
);


INSERT INTO Curso(numCurso, nome, totalCreditos) 
			VALUES(11, 'Ciência da computação', 3200),
				(12, 'Engenharia de software', 3200),
				(13, 'Design digital', 3200);


INSERT INTO Disciplina(numDisc, nome, qntCreditos)
			VALUES(111,  'Calculo numerico', 32),
					(222, 'Banco de dados', 64),
					(333, 'Mobile', 64),
					(444, 'Historia da arte', 32),
					(555, 'Estrutura de dados', 32),
					(666, 'Calculo 2', 64),
					(777, 'Engenharia de software', 32);
					
INSERT INTO Professor(numProf, nome, areaPesquisa)
			VALUES(1, 'Ramon Travant', 'Algoritmos'),
					(2, 'Marcos Salvador', 'Matematica Aplicada'),
					(3, 'Abgair', 'Artes');

INSERT INTO Aluno(numAluno, nome, endereco, cidade, telefone, curso)
			VALUES(11111, 'Edvaldo Carlos Silva', 'Rua joão viada arrais', 'Parambu', '0000012', 11),
					(22222, 'Marcos João Casanova', 'Rua x', 'Quixada', '40028922', 12),
					(33333, 'Ailton Castro', 'Rua a', 'Fortaleza', '9999999', 11),
					(44444, 'Jeferson', 'Rua Z', 'Parambu', '00000000', 12),
					(55555, 'Antonio', 'Rua b', 'xaui', '111111', 13);
					
INSERT INTO RefDisciplinaEmCurso(disciplina, curso)
			VALUES(111, 11),
					(222, 11),
					(222, 12),
					(333, 11),
					(333, 12),
					(333, 13),
					(444, 13),
					(555, 11),
					(555, 12),
					(666, 11),
					(777, 12);
					
INSERT INTO Aula(semestre, nota, disciplina, professor, aluno)
			VALUES('1º semestre de 1998', 8, 222, 1, 11111 ),
					('1º semestre de 1998', 5, 333, 1, 11111),
					('1º semestre de 1998', 9, 444, 3, 55555),
					('1º semestre de 1998', 9, 111, 2, 33333),
					('1º semestre de 1998',7, 222, 2, 22222),
					('2º semestre de 1998',7, 666, 2, 22222),
					('1º semestre de 1998',7, 777, 2, 22222),
					('1º semestre de 1998',1, 777, 1, 11111);


--5. Quais os nomes das disciplinas do curso de Ciência da Computação. 
SELECT D.nome FROM Disciplina D, RefDisciplinaEmCurso R WHERE R.curso = 11 AND D.numDisc = R.disciplina;

--6. Quais os nomes dos cursos que possuem no curriculum a disciplina Cálculo Numérico
SELECT C.nome FROM Curso C, RefDisciplinaEmCurso R WHERE R.disciplina = 111 AND C.numCurso = R.curso;

--7. Quais os nomes das disciplinas que o aluno Marcos João Casanova cursou no 1º semestre de 1998. 
SELECT D.nome FROM Disciplina D, Aula AU, Aluno AL WHERE AU.semestre = '1º semestre de 1998'
														AND AL.nome = 'Marcos João Casanova'
														AND AL.numAluno = AU.aluno
														AND D.numDisc = AU.disciplina;

--8. Quais os nomes de disciplinas que o aluno Ailton Castro foi reprovado.
SELECT D.nome FROM Disciplina D, Aula AU, Aluno AL WHERE AU.nota < 7
														AND AL.nome = 'Ailton Castro'
														AND AL.numAluno = AU.aluno
														AND D.numDisc = AU.disciplina;


--9. Quais os nomes de alunos reprovados na disciplina de Cálculo Numérico no 1º semestre de 1998.
SELECT AL.nome FROM Disciplina D, Aula AU, Aluno AL WHERE AU.semestre = '1º semestre de 1998'
														AND AU.nota < 7
														AND D.nome = 'Calculo numerico'
														AND AU.aluno = AL.numAluno
														AND D.numDisc = AU.disciplina;
														
--10. Quais os nomes das disciplinas ministradas pelo prof. Ramon Travanti.
SELECT D.nome FROM Disciplina D, Professor P, Aula AU WHERE P.nome = 'Ramon Travant'														
															AND P.numProf = AU.professor
															AND D.numDisc = AU.disciplina;

--11. Quais os nomes professores que já ministraram aula de Banco de Dados
SELECT P.nome FROM Disciplina D, Professor P, Aula AU WHERE D.nome = 'Banco de dados'
															AND D.numDisc = AU.disciplina
															AND P.numProf = AU.professor;

--12. Qual a maior e a menor nota na disciplina de Cálculo Numérico no 1º semestre de 1998.   
SELECT MAX(AU.nota) AS Maior_Nota, MIN(AU.nota) AS Menor_Nota FROM Disciplina D, Aula AU WHERE AU.semestre = '1º semestre de 1998'
																							AND D.nome = 'Calculo numerico'
																							AND D.numDisc = AU.disciplina;
	

--13. Qual o nome do aluno e nota que obteve maior nota na disciplina de Engenharia de Software no 1ºsemestre de 1998. 
SELECT AU.nota AS Maior_Nota, AL.nome AS Aluno FROM Disciplina D, Aula AU, Aluno AL WHERE AU.semestre = '1º semestre de 1998'
																							AND D.nome = 'Engenharia de software'
																							AND D.numDisc = AU.disciplina
																							AND AL.numAluno = AU.aluno
																							AND AU.nota = (SELECT MAX(AU.nota) FROM Aula AU, Disciplina D 
																										   						WHERE D.nome = 'Engenharia de software'
																																		AND AU.semestre = '1º semestre de 1998'								
																										   								AND D.numDisc = AU.disciplina);
--14. Quais nomes de alunos, nome de disciplina e nome de professores que cursaram o 1º semestre de 1998 em ordem de aluno. 
SELECT AL.nome AS Aluno, D.nome AS Disciplina, P.nome AS Professor FROM Aluno AL, Disciplina D, Professor P, Aula AU WHERE AU.semestre = '1º semestre de 1998'
																						AND D.numDisc = AU.disciplina
																						AND P.numProf = AU.professor
																						AND AL.numAluno = AU.aluno ORDER BY AL.nome ASC;

--15. Quais nomes de alunos, nome de disciplina e notas do 1º semestre de 1998 no curso de Ciência da Computação.
SELECT AL.nome AS Aluno, D.nome AS Disciplina, AU.nota AS Notas FROM Aluno AL, Disciplina D, Aula AU, Curso C, RefDisciplinaEmCurso REFE 
													WHERE AU.semestre = '1º semestre de 1998'
														AND C.nome = 'Ciência da computação'
														AND REFE.curso = C.numCurso
														AND REFE.disciplina = AU.disciplina 
														AND D.numDisc = AU.disciplina
														AND AL.numAluno = AU.aluno;

--16. Qual a média de notas do professor Marcos Salvador.
SELECT ROUND( AVG(AU.nota), 1) Media_Notas FROM Aula AU, Professor P WHERE P.nome = 'Marcos Salvador'
																AND AU.professor = P.numProf;


--17. Quais nomes de alunos, nomes de disciplinas e notas que tiveram nota entre 5.0 e 7.0 em ordem de disciplina.
SELECT AL.nome AS Aluno, D.nome AS Disciplina, AU.nota AS Notas FROM Aluno AL, Disciplina D, Aula AU 
													WHERE AU.nota BETWEEN 5 AND 7 
													AND D.numDisc = AU.disciplina 
													AND AL.numAluno = AU.aluno;

--18. Qual a média de notas da disciplina Cálculo Numérico no 1º semestre de 1998. 
SELECT ROUND( AVG(AU.nota), 1) Media_Notas FROM Aula AU, Disciplina D WHERE AU.semestre = '1º semestre de 1998'
																AND D.nome = 'Calculo numerico'
																AND D.numDisc = AU.disciplina;

--19. Quantos alunos o professor Abgair teve no 1º semestre de 1998
SELECT COUNT(*) AS QNT_ALUNOS FROM Aula AU, Aluno AL, Professor P WHERE AU.semestre = '1º semestre de 1998'
																	AND P.nome = 'Abgair'
																	AND P.numProf = AU.professor
																	AND AL.numAluno = AU.aluno;
																	
--20. Qual a média de notas do aluno Edvaldo Carlos Silva. 
SELECT ROUND( AVG(AU.nota), 1) Media_Notas FROM Aula AU, Aluno AL WHERE AL.nome = 'Edvaldo Carlos Silva'
																AND AL.numALuno = AU.aluno;

--21. Quais as médias por nome de disciplina de todos os cursos do 1º semestre de 1998 em ordem de disciplina
SELECT D.nome AS disciplinas, ROUND( AVG(AU.nota), 1) AS Media_Notas FROM Aula AU, Disciplina D WHERE AU.semestre = '1º semestre de 1998'
																							AND D.numDisc = AU.disciplina GROUP BY D.nome ORDER BY D.nome;

--22. Quais as médias das notas por nome de professor no 1º semestre de 1998.
SELECT P.nome AS Professores, ROUND( AVG(AU.nota), 1) AS Media_Notas FROM Aula AU, Professor P WHERE AU.semestre = '1º semestre de 1998'
																							AND P.numProf = AU.professor GROUP BY P.nome;

--23. Qual a média por disciplina no 1º semestre de 1998 do curso do Ciência da Computação
SELECT D.nome AS disciplinas, ROUND( AVG(AU.nota), 1) AS Media_Notas FROM Aula AU, Disciplina D, Curso C, RefDisciplinaEmCurso REFE WHERE AU.semestre = '1º semestre de 1998'
																											AND C.nome = 'Ciência da computação'
																											AND REFE.curso = C.numCurso
																											AND REFE.disciplina = AU.disciplina 
																											AND D.numDisc = AU.disciplina  GROUP BY D.nome;

--24. Qual foi quantidade de créditos concluídos (somente as disciplinas aprovadas) do aluno Edvaldo Carlos Silva
SELECT SUM(D.qntCreditos) AS qntCreditos_Concluidos FROM Disciplina D, Aula AU, Aluno AL WHERE AL.nome = 'Edvaldo Carlos Silva' 
																					AND AL.numAluno = AU.aluno
																					AND D.numDisc = AU.disciplina
																					AND AU.nota >= 7;
																					
--25. Quais nomes de alunos e quantidade de créditos que já completaram 70 créditos (somente os aprovados na disciplina). 
SELECT AL.nome AS Aluno, SUM(D.qntCreditos) AS qntCreditos_Concluidos FROM Disciplina D, Aula AU, Aluno AL WHERE AL.numAluno = AU.aluno
																					AND D.numDisc = AU.disciplina
																					AND AU.nota >= 7 GROUP BY AL.nome HAVING SUM(D.qntCreditos) >= 70;


--26. Quais nomes de alunos, nome de disciplina e nome de professores que cursaram o 1º semestre de 1998 e pertencem ao curso de ciência da Computação que possuem nota superior à 8.0. 
SELECT AL.nome AS Aluno, D.nome AS Disciplina, P.nome AS Professor FROM Aluno AL, Disciplina D, Aula AU, Curso C, RefDisciplinaEmCurso REFE, Professor P
													WHERE AU.semestre = '1º semestre de 1998'
														AND C.nome = 'Ciência da computação'
														AND REFE.curso = C.numCurso
														AND REFE.disciplina = AU.disciplina 
														AND D.numDisc = AU.disciplina
														AND AL.numAluno = AU.aluno
														AND P.numProf = AU.professor
														AND AU.nota > 8;


--27. Qual a disciplina com nota mais baixa em qualquer época
SELECT ROUND(MIN(AU.nota), 1) AS Menor_Nota_de_todas FROM Disciplina D, Aula AU WHERE D.numDisc = AU.disciplina;

--28. Qual a disciplina com média de nota mais alta em qualquer época
CREATE VIEW VISÂO_MEDIA_DESCIPLINA(Disciplina, Media) AS
	SELECT D.nome AS Disciplina, ROUND(AVG(AU.nota),1 ) AS Media FROM Disciplina D, Aula AU WHERE D.numDisc = AU.disciplina
																						GROUP BY D.nome;
																						
SELECT Disciplina AS Disciplina_Com_Maior_Media FROM VISÂO_MEDIA_DESCIPLINA WHERE Media = (SELECT MAX(Media) FROM VISÂO_MEDIA_DESCIPLINA) GROUP BY Disciplina;

--29. Quais alunos já concluiram o curso de Ciência da Computação?
SELECT AL.nome AS Alunos_que_Concluiram_Curso FROM Disciplina D, Aluno AL, Aula AU, Curso C, RefDisciplinaEmCurso REFE WHERE C.nome = 'Ciência da computação'
																					AND REFE.curso = C.numCurso
																					AND REFE.disciplina = D.numDisc
																					AND REFE.disciplina = AU.disciplina
																					AND AL.numAluno = AU.aluno
																					AND D.numDisc = AU.disciplina 
																					AND C.totalCreditos - (SELECT SUM(D.qntCreditos) FROM Disciplina D, Aula AU, Aluno AL WHERE 
																																					AL.numAluno = AU.aluno
																																					AND D.numDisc = AU.disciplina
																																					AND AU.nota >= 7 ) = 0  GROUP BY AL.nome;
--30. Ordene as disciplinas por quantidade de reprovações.
SELECT D.nome AS Disciplina, COUNT(*) AS REPROVACOES FROM Disciplina D, Aula AU WHERE D.numDisc = AU.disciplina
																			AND AU.nota < 7 GROUP BY D.nome ORDER BY REPROVACOES 



















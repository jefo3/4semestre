CREATE TABLE if not exists Paciente(
				codpac serial PRIMARY KEY,
				nome varchar(100) NOT NULL,
				endereco varchar(100) NOT NULL,
				telefone varchar(10) NOT NULL
);

CREATE TABLE if not exists Medico(
				crm int PRIMARY KEY NOT NULL, 
				nome varchar(100) NOT NULL,
				endereco varchar(100) NOT NULL,
				telefone varchar(10) NOT NULL,
				especialidade varchar(100) NOT NULL
);

CREATE TABLE if not exists Convenio(
				codconv int PRIMARY KEY NOT NULL, 
				nome varchar(100) NOT NULL
);


CREATE TABLE if not exists Consulta(
				codconsulta serial PRIMARY KEY NOT NULL, 
				data date, 
				horário varchar(30), 
				medico int NOT NULL, 
				paciente int NOT NULL, 
				convenio int NOT NULL, 
				porcent int,
				
				CONSTRAINT consulta_fkey1 FOREIGN KEY(medico)
										REFERENCES Medico(crm),
	
				CONSTRAINT consulta_fKey2 FOREIGN KEY(paciente)
										REFERENCES Paciente(codpac),
				
				CONSTRAINT consulta_fkey3 FOREIGN KEY(convenio)
										REFERENCES Convenio(codconv)
);

CREATE TABLE if not exists Atende(
				medico int NOT NULL, 
				convenio int NOT NULL,
				
				CONSTRAINT atende_pkey PRIMARY KEY(medico, convenio),
				
				CONSTRAINT atende_fkey1 FOREIGN KEY(medico)
										REFERENCES Medico(crm),
		
				CONSTRAINT atende_fkey2 FOREIGN KEY(convenio)
										REFERENCES Convenio(codconv)
);

CREATE TABLE if not exists Possui(
				paciente int NOT NULL, 
				convenio int, 
				tipo varchar(40), 
				vencimento date,
	
				CONSTRAINT possui_pkey PRIMARY KEY(paciente, convenio),
				
				CONSTRAINT possui_fkey1 FOREIGN KEY(paciente)
									   REFERENCES Paciente(codpac),
				
				CONSTRAINT possuifkey2 FOREIGN KEY(convenio)
									   REFERENCES Convenio(codconv)
);

INSERT INTO Paciente (nome, endereco, telefone) 
			VALUES('João', 'Rua 1', '9809-9756' ),
					('José', 'Rua B', '3621-8978' ), 
					('Maria', 'Rua 10', '4567-9872' ),  
					('Joana', 'Rua j', '3343-9889' );
			
INSERT INTO Medico(crm, nome, endereco, telefone, especialidade)
			VALUES(18739, 'Elias', 'Rua X', '8738-1221', 'Pediatria'),
					(7646, 'Ana', 'Av Z', '7829-1233', 'Obstetricia'),
					(39872, 'Pedro', 'Tv H', '9888-2333', 'Oftalmologia');


INSERT INTO Convenio(codconv, nome)
			VALUES(189, 'Cassi'),
					(232, 'Unimed'),
					(454, 'Santa Casa'),
					(908, 'Copasa'),
					(435, 'São Lucas');

INSERT INTO Consulta(data, horário, medico, paciente, convenio, porcent)
		VALUES ('10/05/2013', '10:00', 18739, 1, 189, 5),
				('12/05/2013', '10:00', 7646, 2, 232, 10),
				('12/05/2013', '11:00', 18739, 3, 908, 15),
				('13/05/2013', '10:00', 7646, 4, 435, 13),
				('14/05/2013', '13:00', 7646, 2, 232, 10),
				('14/05/2013', '14:00', 39872, 1, 189, 5);
				
INSERT INTO Atende(medico, convenio)
			VALUES(18739, 189),
					(18739, 908),
					(7646, 232),
					(39872, 189);
					
INSERT INTO Possui(paciente, convenio, tipo, vencimento)
			VALUES(1, 189, 'E', '31/12/2016'),
					(2, 232, 'S', '31/12/2014'),
					(3, 908, 'S', '31/12/2017'),
					(4, 435, 'E', '31/12/2016'),
					(1, 232, 'S', '31/12/2015');



--SELECT * FROM Consulta


--1. Atualize o endereço do paciente João para ‘Rua do Bonde’
UPDATE Paciente SET endereco = 'Rua do Bonde' WHERE nome = 'João';

--2. Atualize os dados do medico Elias para ‘Rua Z’ e telefone ‘9838-7867’
UPDATE Medico SET (endereco, telefone) = ('Rua Z', '9838-7867') 
				WHERE nome = 'Elias';

--3. Atualize todos os tipos dos convênios que os pacientes possuem para ‘S’
UPDATE Possui SET tipo = 'S' WHERE tipo != 'S';

--4. Exclua a informação que o paciente José tem o convenio 232
DELETE FROM Possui WHERE paciente = (SELECT codpac FROM Paciente WHERE nome = 'José');

--5. Exclua a consulta realizada do dia 14/05/2013 as 14:00.
DELETE FROM Consulta WHERE (data, horário) = ('14/05/2013', '14:00');

--6. Altere o nome da coluna especialidade, da tabela médico, para especialização.
ALTER TABLE Medico RENAME especialidade TO especialização;

--7. Altere o tipo de dado da coluna nome, da tabela convenio, para varchar(200).
ALTER TABLE Convenio ALTER COLUMN nome TYPE varchar(200); 

--8. Acrescente a coluna Valor na tabela consulta e atualize todas as consultas para o valor de R$100,00.
ALTER TABLE Consulta ADD COLUMN valor real;
UPDATE Consulta SET valor = 100.00;



				









































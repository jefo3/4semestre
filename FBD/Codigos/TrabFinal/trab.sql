
-- ## CREATERS ##
CREATE TABLE if not exists Usuario(
	cpf varchar(20) not null primary key,
	nome varchar(100) not null,
	email varchar(100),
	dataNasc date
);

CREATE TABLE if not exists Funcionario(
	login varchar(100) not null,
	senha varchar(100) not null
)INHERITS(Usuario);


CREATE TABLE if not exists Onibus(
	idOnibus serial not null primary key,
	capacidade int not null,
	tipo varchar(50) not null
);

CREATE TABLE if not exists Poltrona(
	idPoltrona serial primary key,
	num int not null,
	vazio bool,	
	idOnibus int not null,
	
	CONSTRAINT poltrona_fkey1 FOREIGN KEY(idOnibus)
										REFERENCES Onibus(idOnibus)

);

CREATE TABLE if not exists Cidade(
	idCidade serial not null primary key,
	nome varchar(100) not null,
	estado varchar(100) not null
);


CREATE TABLE if not exists Rota(
	idRota serial not null primary key,
	tempoViagem int not null,
	
	dataHoraViagem timestamp  not null,
	
	idOnibus int not null,
	origem int not null,
	destino int not null,
	
	CONSTRAINT rota_fkey1 FOREIGN KEY(idOnibus)
										REFERENCES Onibus(idOnibus),
	CONSTRAINT rota_fkey2 FOREIGN KEY(origem)
										REFERENCES Cidade(idCidade),
	CONSTRAINT rota_fkey3 FOREIGN KEY(destino)
										REFERENCES Cidade(idCidade)	
);


-- ## FUNCTIONS ##

CREATE OR REPLACE FUNCTION cria_poltrona(idOnibus integer, capacidade integer)
RETURNS void AS $$
	
	DECLARE
    	i integer := 1;
		
	BEGIN
		
		WHILE i <= capacidade LOOP
			
			INSERT INTO Poltrona (num, vazio, idOnibus)
					VALUES (i,true, idOnibus);
					
			i:= i+1;
			
		END LOOP;
	
	END;
	
$$
LANGUAGE PLPGSQL










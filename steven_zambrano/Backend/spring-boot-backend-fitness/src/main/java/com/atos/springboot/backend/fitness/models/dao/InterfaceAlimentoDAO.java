package com.atos.springboot.backend.fitness.models.dao;

import java.util.List;

import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.CrudRepository;
import org.springframework.data.repository.query.Param;
import org.springframework.transaction.annotation.Transactional;

import com.atos.springboot.backend.fitness.models.entity.Alimento;

public interface InterfaceAlimentoDAO extends CrudRepository<Alimento, Long> {


	
	//Metodo que nos permite, mostrar todos los alimentos del usuario a través de su id, pasosela por parametros.
	@Query(value = "SELECT a FROM Alimento a JOIN a.usuarios u WHERE u.id = :id")
	public List<Alimento> getAlimentoUsuarios( @Param("id") Long id);


	//Metodo que hace la suma de todos los alimentos que el usuario ha agreado a su perfil
	@Query(value = "SELECT SUM(a.valorEnergetico) FROM Alimento a JOIN a.usuarios u WHERE u.id = :id")
	public int sumaAlimentos( @Param("id") Long id);

	
	//Metodo que permite relaciónar los alimentos que usuario agrega su perfil.
	@Modifying
	@Transactional
	@Query(value = "INSERT INTO `usuarios_alimentos` (usuarios_id, alimentos_id) VALUES (:id_usuario, :id_alimento)", nativeQuery = true)
	public void insertarAlimentoUser(@Param("id_usuario") Long id_usuario, @Param("id_alimento") Long id_alimento);
	

}

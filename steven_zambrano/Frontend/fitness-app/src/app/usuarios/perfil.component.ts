import { Component, OnInit } from '@angular/core';
import { UsuarioService } from './usuario.service';
import { Router, ActivatedRoute } from '@angular/router';
import { Usuario } from './usuario';
import { Alimento } from '../admin/alimento';
import { AuthService } from './auth.service';
import { Objetivo } from '../objetivos/objetivo';
import Swal from 'sweetalert2';


@Component({
  selector: 'app-perfil',
  templateUrl: './perfil.component.html',
  styleUrls: ['./perfil.component.css']
})
export class PerfilComponent implements OnInit {

  private usuario: Usuario = new Usuario();

  alimentos: Alimento[];

  alimentos2: Alimento[];

  private errores: string[];

  suma:number;

  pesoideal:number;

  caloriasDiarias:number;

  objetivo: Objetivo = new Objetivo();


  constructor(private usuarioService: UsuarioService, private router: Router,
    private activatedRouter: ActivatedRoute, private authService: AuthService) { }

  ngOnInit() {

    this.cargarCliente();

    this.usuarioService.getAlimentos().subscribe(alimentos => this.alimentos  = alimentos);

    this.usuarioService.getAlimentosUsuarios(this.authService.usuario.id).subscribe(alimentos2 => this.alimentos2  = alimentos2);

    this.usuarioService.sumaAlimentos(this.authService.usuario.id).subscribe(suma => this.suma = suma);

    this.usuarioService.pesoIdealUser(this.authService.usuario.id).subscribe(pesoideal => this.pesoideal = pesoideal);

    this.usuarioService.objetivoDatosUser(this.authService.usuario.id).subscribe(objetivo => this.objetivo = objetivo);

    this.usuarioService.caloriasDiarias(this.authService.usuario.id).subscribe(caloriasDiarias => this.caloriasDiarias = caloriasDiarias);

    
  }

  /**
   * Nos permite cargar el perfil del usuario a través de su id
   */

  public cargarCliente(): void{
    this.activatedRouter.params.subscribe(params => {
      let id = params['id']
      if(id){
        this.usuarioService.getUsario(id).subscribe( (usuario) => this.usuario = usuario)
      }
    })
  }

  /*
    Metodo el cual llamos al servicio de usuario.service para realizar el insert
  */
  public insertarAlimentosUser(usuario_id, alimento_id): void{

    this.usuarioService.insertarAlimentosUser(usuario_id, alimento_id).subscribe(

      any => {
        this.router.navigate([`perfil/${this.usuario.id}`])
        Swal.fire('Alimento agregado', `${this.usuario.nombre} has actulizado tu perfil con éxito!`, 'success')
        .then((result) => {
          location.reload(true);
        })
      },
   err => {
    

    if (err.status == 500) { 
      Swal.fire('Error', 'Lo sentimos por el momento no se puede agregar dos veces el mismo alimento', 'error');
    }

    this.errores = err.error.errors as string[];

    
     console.error('Código del error desde el backend' + err.status);
   
   }   
    )


  }


  /*Funcioón que utilizamos para recargar la pagina , por problemas del array de la lista de alimentos
  del usuario*/

  public recargarPagina() {

    location.reload(true);

  }



}

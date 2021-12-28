import { Component } from '@angular/core';
import { registerPlugin } from '@capacitor/core';

export interface EchoPlugin {
  ve();
}

const Echo = registerPlugin<EchoPlugin>('Echo');
export default Echo;

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {

  constructor() {}
  
  async doVE() {
    await Echo.ve();
  }
}

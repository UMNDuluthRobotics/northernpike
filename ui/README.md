# Northern Pike Client UI

This project was generated with [Angular CLI](https://github.com/angular/angular-cli) version 6.2.3.

## Development setup

1. Install [Node.js and NPM](https://nodejs.org/en/download/).

2. Install Angular CLI by running ` npm install -g @angular/cli --save` in the project directory.

3. Install project dependencies listed in `package.json` by running `npm install`.

## Development server

Run `ng serve --open` for a dev server. `http://localhost:4200/` should open in your default browser. The app will automatically reload if you change any of the source files.

## Code scaffolding

Run `ng generate component component-name` to generate a new component. You can also use `ng generate directive|pipe|service|class|guard|interface|enum|module`.

## Build

Run `ng build` to build the project. The build artifacts will be stored in the `dist/` directory. Use the `--prod` flag for a production build.

## Video Stream Setup

#### To build and install mjpg-streamer
```
git clone https://github.com/jacksonliam/mjpg-streamer
sudo apt-get install cmake libjpeg8-dev
sudo apt-get install gcc g++
cd mjpg-streamer/mjpg-streamer-experimental
make
sudo make install
export LD_LIBRARY_PATH=.
```
#### To run mjpg-streamer
```
./mjpg_streamer -o "output_http.so -w ./www" -i "input_uvc.so"
```

## Further help

To get more help on the Angular CLI use `ng help` or go check out the [Angular CLI README](https://github.com/angular/angular-cli/blob/master/README.md).

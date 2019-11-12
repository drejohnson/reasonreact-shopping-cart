const path = require("path");
const CopyPlugin = require("copy-webpack-plugin");
const { CleanWebpackPlugin } = require("clean-webpack-plugin");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const ScriptExtHtmlPlugin = require("script-ext-html-webpack-plugin");
const JsConfigWebpackPlugin = require("js-config-webpack-plugin");
const ImageConfigWebpackPlugin = require("image-config-webpack-plugin");
const ScssConfigWebpackPlugin = require("scss-config-webpack-plugin");
const TerserPlugin = require("terser-webpack-plugin");
const outputDir = path.join(__dirname, "dist/");

module.exports = {
  entry: {
    app: "./src/Index.bs.js"
  },
  mode: "production",
  output: {
    path: outputDir,
    chunkFilename: "static/[name].[chunkhash:8].js",
    filename: "static/[name].[chunkhash:8].js",
    publicPath: "/"
  },
  plugins: [
    new CopyPlugin([
      {
        from: "public",
        to: `${outputDir}`,
        ignore: ["index.html"]
      }
    ]),
    new CleanWebpackPlugin(),
    new JsConfigWebpackPlugin(),
    new ScssConfigWebpackPlugin(),
    new ImageConfigWebpackPlugin(),
    new HtmlWebpackPlugin({
      minify: {
        collapseWhitespace: true,
        removeComments: true,
        removeRedundantAttributes: true,
        removeScriptTypeAttributes: true,
        removeStyleLinkTypeAttributes: true,
        sortAttributes: true,
        sortClassName: true,
        useShortDoctype: true,
        minifyCSS: true,
        minifyJS: true,
        caseSensitive: true
      },
      hash: true,
      inject: true,
      template: "./public/index.html"
    }),
    new ScriptExtHtmlPlugin({
      defaultAttribute: "defer",
      module: ["app"]
    })
  ],
  optimization: {
    nodeEnv: "production",
    concatenateModules: true,
    minimizer: [
      new TerserPlugin({
        cache: true,
        parallel: true,
        sourceMap: true, // Must be set to true if using source-maps in production
        terserOptions: {
          // https://github.com/webpack-contrib/terser-webpack-plugin#terseroptions
        }
      })
    ],
    splitChunks: {
      chunks: "all",
      cacheGroups: {
        commons: {
          test: /node_modules/,
          chunks: "initial",
          name: "common",
          priority: 10,
          enforce: true
        }
      }
    }
  },
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 3000,
    historyApiFallback: true
  }
};
